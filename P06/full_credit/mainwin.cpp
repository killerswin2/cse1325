#include "parent.h"
#include "student.h"
#include "mainwin.h"

Mainwin::Mainwin() : display{new Gtk::Label}{
    set_default_size(400,200);
    set_title("SMART");
    //Vertical Box
    Gtk::Box *vbox = Gtk::manage(new Gtk::VBox);
    add(*vbox);

    //MENU
    Gtk::MenuBar *menubar= Gtk::manage(new Gtk::MenuBar);
    vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);
    
    //Label
    vbox->pack_start(*display,Gtk::PACK_SHRINK,0);

    //FILE
    Gtk::MenuItem *file_menu = Gtk::manage(new Gtk::MenuItem("File"));
    menubar->append(*file_menu);
    Gtk::Menu *file_sub_menu = Gtk::manage(new Gtk::Menu());
    file_menu->set_submenu(*file_sub_menu);

    //FILE -> NEW SCHOOl
    Gtk::MenuItem *new_school_menu_item = Gtk::manage(new Gtk::MenuItem("New School"));
    new_school_menu_item->signal_activate().connect([this]{this->on_new_school_click();});
    file_sub_menu->append(*new_school_menu_item);

    //FILE -> QUIT
    Gtk::MenuItem *quit_menu_item = Gtk::manage(new Gtk::MenuItem("Quit"));
    quit_menu_item->signal_activate().connect([this]{this->on_quit_click();});
    file_sub_menu->append(*quit_menu_item);
    
    //INSERT
    Gtk::MenuItem *insert_menu = Gtk::manage(new Gtk::MenuItem("Insert"));
    menubar->append(*insert_menu);
    Gtk::Menu *insert_sub_menu = Gtk::manage(new Gtk::Menu());
    insert_menu->set_submenu(*insert_sub_menu);

    //INSERT -> NEW STUDENT
    Gtk::MenuItem *new_student_menu_item = Gtk::manage(new Gtk::MenuItem("New Student"));
    new_student_menu_item->signal_activate().connect([this]{this->on_new_student_click();});
    insert_sub_menu->append(*new_student_menu_item);

    //INSERT -> NEW PARENT
    Gtk::MenuItem *new_parent_menu_item = Gtk::manage(new Gtk::MenuItem("New Parent"));
    new_parent_menu_item->signal_activate().connect([this]{this->on_new_parent_click();});
    insert_sub_menu->append(*new_parent_menu_item);

    //RELATE
    Gtk::MenuItem *relate_menu = Gtk::manage(new Gtk::MenuItem("Relate"));
    menubar->append(*relate_menu);
    Gtk::Menu *relate_sub_menu = Gtk::manage(new Gtk::Menu());
    relate_menu->set_submenu(*relate_sub_menu);

    //RELATE -> STUDENTS TO PARENTS
    Gtk::MenuItem *students_to_parents = Gtk::manage(new Gtk::MenuItem("Student to Parent"));
    students_to_parents->signal_activate().connect([this] {this->on_student_parent_click();});
    relate_sub_menu->append(*students_to_parents);

    vbox->show_all();
}
Mainwin::~Mainwin(){ }


void Mainwin::on_new_school_click(){
    
}
void Mainwin::on_new_student_click(){
    
}
void Mainwin::on_new_parent_click(){
    
}
void Mainwin::on_student_parent_click(){
    
}  
void Mainwin::on_quit_click(){
    
}