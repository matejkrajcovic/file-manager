#ifndef FILE_MANAGER_WINDOW_H
#define FILE_MANAGER_WINDOW_H

#include <gtkmm.h>

class Window : public Gtk::Window {

public:
	Window();
	virtual ~Window();

protected:
	class FileListColumns : public Gtk::TreeModel::ColumnRecord {

	public:
		FileListColumns() {
			add(fileName);
		};

		Gtk::TreeModelColumn<Glib::ustring> fileName;
	};

	FileListColumns fileListColumns;

	Gtk::TreeView fileListView;
	Glib::RefPtr<Gtk::ListStore> fileListModel;
};

#endif // FILE_MANAGER_WINDOW_H
