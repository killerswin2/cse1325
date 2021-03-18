#ifndef __ENTRYDIALOG_H
#define __ENTRYDIALOG_H
#include <gtkmm.h>

class EntryDialog : public Gtk::MessageDialog {
    public:
        void set_text(Glib::ustring text);
        Glib::ustring get_text();
        EntryDialog(Gtk::Window& parent, const Glib::ustring& message, bool use_markup = false,
                    Gtk::MessageType type = Gtk::MESSAGE_INFO, Gtk::ButtonsType buttons = Gtk::BUTTONS_OK, bool modal = false );
    private:
        Gtk::Entry* entry;
};


#endif