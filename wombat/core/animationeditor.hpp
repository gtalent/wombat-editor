#ifndef WOMBATCORE_ANIMATIONEDITOR_HPP
#define WOMBATCORE_ANIMATIONEDITOR_HPP

#include <QWidget>
#include <QAbstractTableModel>

#include <models/editormodels.hpp>

#include <editorcore/editorwidget.hpp>
#include <editorcore/editorwidgetparams.hpp>

namespace Ui {
class AnimationEditor;
}

namespace wombat {
namespace core {

using namespace editor;

class AnimationEditor: public EditorWidget {
	Q_OBJECT

	private:
		class ImageTableModel: public QAbstractTableModel {
			private:
				models::Animation &m_model;
				QMap<QString, QPixmap> &m_pixMaps;
				QString &m_projectPath;

			public:
				ImageTableModel(models::Animation &model, QMap<QString, QPixmap> &pixMaps, QString &projectPath);

				QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

				virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;

				virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;

				QVariant headerData(int index, Qt::Orientation orientation, int role) const;
		};

		//COMMANDS
		class Command: public QUndoCommand {
			private:
				AnimationEditor *m_parent = nullptr;
				models::Animation m_before;
				models::Animation m_after;

			public:
				Command(AnimationEditor *parent, models::Animation before, models::Animation after);

				void undo();

				void redo();
		};

	private:
		Ui::AnimationEditor *ui = nullptr;
		ImageTableModel *m_modelView = nullptr;
		QString m_projectPath;
		QMap<QString, QPixmap> m_pixMaps;
		models::Animation m_model;

	public:
		AnimationEditor(EditorWidgetParams);

		~AnimationEditor();

		int saveFile();

	public slots:
		void addBtnClick();

		void rmBtnClick();

		void tableClicked();

	protected:
		void updateModel(models::Animation);
};

}
}

#endif
