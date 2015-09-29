#ifndef FILE_LIST_VIEW_H
#define FILE_LIST_VIEW_H

#include <gtkmm.h>
#include <string>

class FileListView : public Gtk::ScrolledWindow {

public:
    FileListView();
    void setDirectory(std::string directory);

private:
    class FileListColumns : public Gtk::TreeModel::ColumnRecord {

	public:
		FileListColumns() {
			add(fileName);
		};

		Gtk::TreeModelColumn<Glib::ustring> fileName;
	};

    FileListColumns columns;

    Gtk::TreeView view;
    Glib::RefPtr<Gtk::ListStore> model;
};

#endif // FILE_LIST_VIEW_H
