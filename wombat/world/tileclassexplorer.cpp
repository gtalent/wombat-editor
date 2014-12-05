#include <QDebug>
#include <QHeaderView>
#include <QTableView>
#include <QVBoxLayout>
#include <models/paths.hpp>
#include "tileclassexplorer.hpp"

namespace wombat {
namespace world {

using editor::DockWindow;
using editor::DockWindowParams;
using models::TileClass;
using models::Path_TileClass;

const QString TileClassExplorer::DockId = "TileClassExplorer";

TileClassExplorer::TileClassTable::TileClassTable(TileClassExplorer *parent,
                                                  QMap<QString, TileClass> tcs) {
	for (auto tc = tcs.begin(); tc != tcs.end(); tc++) {
		auto key = tc.key();
		auto val = tc.value();
		auto &worldUtil = parent->m_worldUtil;

		try {
			key = key.left(key.lastIndexOf("."));
		} catch (...) {
		}
		m_model.push_back(Row(key, worldUtil.firstImage(val.LowerAnim.Animation)));
	}
}

QVariant TileClassExplorer::TileClassTable::data(const QModelIndex &index, int role) const {
	if (role == Qt::DecorationRole || role == Qt::DisplayRole) {
		const int r = index.row();
		const int c = index.column();

		switch (c) {
			case 0:
				return m_model[r].img;
			case 1:
				return m_model[r].name;
		}
	}
	return QVariant();
}

int TileClassExplorer::TileClassTable::rowCount(const QModelIndex&) const {
	return m_model.size();
}

int TileClassExplorer::TileClassTable::columnCount(const QModelIndex&) const {
	return 2;
}

QVariant TileClassExplorer::TileClassTable::headerData(int index, Qt::Orientation orientation, int role) const {
	if (role == Qt::DisplayRole) {
		if (orientation == Qt::Horizontal) {
			switch (index) {
				case 0:
					return "";
				case 1:
					return tr("Tile Class");
			}
		} else {
			return index + 1;
		}
	}
	return QVariant();
}

TileClassExplorer::TileClassTable::Row TileClassExplorer::TileClassTable::row(int row) {
	if (row > -1 && row < m_model.size()) {
		return m_model[row];
	}
	return TileClassExplorer::TileClassTable::Row();
}

// TileClassExplorer

TileClassExplorer::TileClassExplorer(DockWindowParams args):
DockWindow(args), m_worldUtil(args.modelio) {
	m_modelio = args.modelio;
	setWindowTitle(tr("Tile Classes"));

	auto contents = new QWidget();
	auto layout = new QVBoxLayout(contents);
	m_tileTable = new QTableView(this);
	m_tileTable->horizontalHeader()->setStretchLastSection(true);
	m_tileTable->horizontalHeader()->setVisible(false);
	m_tileTable->verticalHeader()->setVisible(false);
	m_tileTable->setSelectionBehavior(QAbstractItemView::SelectRows);
	m_tileTable->setSelectionMode(QAbstractItemView::SingleSelection);
	layout->addWidget(m_tileTable);
	setWidget(contents);

	loadTileClassList();
}

TileClassExplorer::~TileClassExplorer() {
	unsubscribe();
	if (m_tileTableModel) {
		delete m_tileTableModel;
	}
}

QString TileClassExplorer::objectId() const {
	return DockId;
}

void TileClassExplorer::loadTileClassList() {
	auto tileClasses = m_modelio->readModels<TileClass>(Path_TileClass);
	auto tileTable = new TileClassTable(this, tileClasses);
	subscribe(tileClasses);
	setTableModel(tileTable);
}

QString TileClassExplorer::selectedTile() {
	QString retval = "";
	int row = m_tileTable->currentIndex().row();

	QString name = m_tileTableModel->row(row).name;
	if (name != "") {
		retval = Path_TileClass + name;
	}

	return retval;
}

void TileClassExplorer::setTableModel(TileClassTable *tileTable) {
	if (m_tileTableModel) {
		delete m_tileTableModel;
	}
	m_tileTableModel = tileTable;
	m_tileTable->setModel(m_tileTableModel);
}

void TileClassExplorer::subscribe() {
	auto tileClasses = m_modelio->readModels<TileClass>(Path_TileClass);
	subscribe(tileClasses);
}

void TileClassExplorer::subscribe(const QMap<QString, TileClass> &tileClasses) {
	unsubscribe();
	for (auto tc = tileClasses.begin(); tc != tileClasses.end(); tc++) {
		auto key = Path_TileClass + tc.key();
		auto val = tc.value();
		auto lowerAnim = val.LowerAnim.Animation;
		auto upperAnim = val.UpperAnim.Animation;

		m_tcSubs.push_back(key);
		m_tcSubs.push_back(lowerAnim);
		m_tcSubs.push_back(upperAnim);

		m_modelio->connectOnUpdate(key, this, SLOT(loadTileClassList()));
		if (lowerAnim != "") {
			m_modelio->connectOnUpdate(lowerAnim, this, SLOT(loadTileClassList()));
		}
		if (upperAnim != "") {
			m_modelio->connectOnUpdate(upperAnim, this, SLOT(loadTileClassList()));
		}
	}
}

void TileClassExplorer::unsubscribe() {
	for (auto sub : m_tcSubs) {
		m_modelio->disconnectOnUpdate(sub, this, SLOT(loadTileClassList()));
	}
	m_tcSubs.clear();
}

}
}
