#include "window.h"
#include <iostream>

Window::Window() {
	set_border_width(5);
	set_title("File Manager");

	add(fileListView);

	fileListModel = Gtk::ListStore::create(fileListColumns);

	fileListView.set_model(fileListModel);

	Gtk::TreeModel::Row row = *(fileListModel->append());
	row[fileListColumns.fileName] = "file.cc";

	row = *(fileListModel->append());
	row[fileListColumns.fileName] = "hello-world";

	row = *(fileListModel->append());
	row[fileListColumns.fileName] = "file.h";

	fileListView.append_column("File name", fileListColumns.fileName);

	show_all_children();
}

Window::~Window() {}
