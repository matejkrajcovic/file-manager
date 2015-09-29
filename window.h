#ifndef FILE_MANAGER_WINDOW_H
#define FILE_MANAGER_WINDOW_H

#include "file_list_view.h"
#include <gtkmm.h>

class Window : public Gtk::Window {

public:
	Window();
	virtual ~Window();

protected:
    FileListView fileListView;
};

#endif // FILE_MANAGER_WINDOW_H
