#include "App.h"
#include "MainFrame.h"
#include <wx/wx.h>
//Entry point for application
wxIMPLEMENT_APP(App);

bool App::OnInit(){

      //Create main window on startup
      MainFrame* mainFrame = new MainFrame("Sudoku Application");
      mainFrame->SetClientSize(800,800);
      mainFrame->Center();
      mainFrame->Show();


      return true;
}
