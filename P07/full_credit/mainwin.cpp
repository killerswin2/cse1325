#include "parent.h"
#include "student.h"
#include "mainwin.h"
#include "entrydialog.h"

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
    display->set_hexpand(true);
    display->set_vexpand(true);
    show_data();
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

void Mainwin::show_data(){
    Glib::ustring label_text;

    label_text = "Students\n";

    //display students
    for(int i = 0; i< students.size(); ++i){
        label_text += students[i].full_info()  + "\n";
    }

    label_text += "\n\nParents\n";
    //display parents
    for(int i = 0; i< parents.size(); ++i){
        label_text += parents[i].full_info()  + "\n";
    }
    display->set_label(label_text);
}


void Mainwin::on_new_school_click(){
    students.erase(students.begin(), students.end());
    parents.erase(parents.begin(), parents.end());
    show_data();
}

void Mainwin::on_new_student_click(){
    //Student Name 
    Glib::ustring name;
    EntryDialog Name{*this,"Student name?"};
    Name.run();
    name = Name.get_text();

    //Student Email
    Glib::ustring email;  
    EntryDialog Email{*this,"Student email?"};
    Email.run();
    email = Email.get_text();
    
    //Student Grade
    std::string grade_string;
    EntryDialog Grade{*this,"Student grade"};
    Grade.run();
    grade_string = Grade.get_text();
    int grade = std::stoi(grade_string);
    
    //Create Student
    students.push_back(Student{name, email, grade });
    show_data();
}
void Mainwin::on_new_parent_click(){
    //Parent Name 
    Glib::ustring name;
    EntryDialog Name{*this,"Parent name?"};
    Name.run();
    name = Name.get_text();

    //Student Email
    Glib::ustring email;  
    EntryDialog Email{*this,"Parent email?"};
    Email.run();
    email = Email.get_text();
    
    //Create Parent
    parents.push_back(Parent{name, email});
    show_data();
}

void Mainwin::on_student_parent_click(){
    //Student Dialog
    EntryDialog student_name{*this, "Student Name?"};
    std::string student_names;
    for(int i = 0; i < students.size(); ++i){
        student_names += std::to_string(i) + " " + students[i].to_string() + "\n";
    }
    student_name.set_secondary_text(student_names);
    student_name.run();
    
    //Student index
    std::string student_index_string;
    student_index_string = student_name.get_text();
    int student_index = std::stoi(student_index_string);

    //Parent Dialog
    EntryDialog parent_name{*this, "Parent Name?"};
    std::string parent_names;
    for(int i = 0; i< parents.size(); ++i){
        parent_names += std::to_string(i) + " " + parents[i].to_string() + "\n";
    }
    parent_name.set_secondary_text(parent_names);
    parent_name.run();

    //Parent index
    std::string parent_index_string;
    parent_index_string = parent_name.get_text();
    int parent_index = std::stoi(parent_index_string);


    //Relate Student to Parent
    parents[parent_index].add_student(students[student_index]);

    //Relate Parent to Student
    students[student_index].add_parent(parents[parent_index]);

    //Update Display
    show_data();

}  
void Mainwin::on_quit_click(){
    close();   
}