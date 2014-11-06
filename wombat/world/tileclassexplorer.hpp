#ifndef WOMBAT_WORLD_TILECLASSEXPLORER_HPP
#define WOMBAT_WORLD_TILECLASSEXPLORER_HPP

#include <QAbstractTableModel>
#include <QTableView>
#include <models/models.hpp>
#include <editorcore/dockwindow.hpp>
#include "worldutil.hpp"

namespace wombat {
namespace world {

class TileClassExplorer: public editor::DockWindow {
	Q_OBJECT
	private:
		class TileClassTable: public QAbstractTableModel {
			private:
				struct Row {
					QString name;
					QPixmap img;

					Row() = default;

					Row(QString name, QPixmap img) {
						this->name = name;
						this->img = img;
					}
				};
				QVector<Row> m_model;

			public:
				TileClassTable(TileClassExplorer *parent, QMap<QString, models::TileClass> classes);

				QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

				virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;

				virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

				QVariant headerData(int index, Qt::Orientation orientation, int role) const;

				Row row(int row);
		};

	public:
		static const QString DockId;

	private:
		QTableView *m_tileTable = nullptr;
		TileClassTable *m_tileTableModel = nullptr;
		QString m_projectPath;
		editor::ModelIoManager *m_modelio = nullptr;
		WorldUtil m_worldUtil;
		QVector<QString> m_tcSubs;

	public:
		TileClassExplorer(editor::DockWindowParams);

		~TileClassExplorer();

		QString objectId() const override;

	public slots:
		void loadTileClassList();

		/**
		 * @return the relative path of the currently selected TileClass
		 */
		QString selectedTile();

	private:
		void setTableModel(TileClassTable *tileTable);

		void subscribe();

		void subscribe(const QMap<QString, models::TileClass> &tileClasses);

		void unsubscribe();
};

}
}

#endif
