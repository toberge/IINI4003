#include <gtkmm.h>

class Window : public Gtk::Window {
public:
  Gtk::VBox vbox;
  Gtk::Label firstNameLabel;
  Gtk::Entry firstNameEntry;
  Gtk::Label lastNameLabel;
  Gtk::Entry lastNameEntry;
  Gtk::Button button;
  Gtk::Label label;

  Window() {
    // Set up widgets
    button.set_label("Combine!");
    button.set_sensitive(false); // sensitive == enabled

    firstNameLabel.set_text("First name");
    lastNameLabel.set_text("Last name");

    // Pack widgets
    vbox.pack_start(firstNameLabel);
    vbox.pack_start(firstNameEntry);
    vbox.pack_start(lastNameLabel);
    vbox.pack_start(lastNameEntry);
    vbox.pack_start(button); //Add the widget button to vbox
    vbox.pack_start(label);  //Add the widget label to vbox

    // Set up self
    add(vbox);  //Add vbox to window
    set_title("Name Concatenator");
    set_border_width(64);
    show_all(); //Show all widgets

    // Add signal handlers
    firstNameEntry.signal_changed().connect([this]() {
      button.set_sensitive(firstNameEntry.get_text() != "" && lastNameEntry.get_text() != "");
    });

    lastNameEntry.signal_changed().connect([this]() {
      button.set_sensitive(firstNameEntry.get_text() != "" && lastNameEntry.get_text() != "");
    });

    /* firstNameEntry.signal_activate().connect([this]() { */
    /*   button.set_sensitive(firstNameEntry.get_text() != "" && lastNameEntry.get_text() != ""); */
    /* }); */

    // Concatenate names
    button.signal_clicked().connect([this]() {
      label.set_text(firstNameEntry.get_text() + " "
                   + lastNameEntry.get_text());
    });
  }
};

int main() {
  Gtk::Main gtk_main;
  Window window;
  gtk_main.run(window);
}

// vim:softtabstop=2:sw=2
