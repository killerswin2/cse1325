#include "mainwin.h"

int main(int argc, char *argv[]){
    auto app = Gtk::Application::create(argc, argv, "exn5470.full.main");
    Mainwin win;
    return app->run(win);
}