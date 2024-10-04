#include "MainFrame.h"
#include "gameFrame.h"
#include <wx/wx.h>
#include <wx/grid.h>
#include "GameGrid.h"

enum buttonIDs{
    EASYOPTION = 1,
    HARDOPTION = 2

};
//Defines initial screen and allows selection of easy or hard grid
MainFrame::MainFrame(const wxString& title): wxFrame(nullptr, wxID_ANY, title){

    wxPanel* panel = new wxPanel(this);
    //Defines buttons and their event binding
    wxButton* button_Easy = new wxButton(panel, EASYOPTION, "Easy", wxPoint(300, 300), wxSize(200, 50));

    wxButton* button_Hard = new wxButton(panel, HARDOPTION, "Hard", wxPoint(300, 500), wxSize(200, 50));


    button_Easy->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

    button_Hard->Bind(wxEVT_BUTTON, &MainFrame::OnButtonClicked, this);

}

void MainFrame::OnButtonClicked(wxCommandEvent& evt){
    //Shift focus from initial screen
    this->Close();
    //Initialize game grid variable
    int** gameValues;
    gameValues = new int*[9];
    for (int i = 0; i < 9; ++i) {
        gameValues[i] = new int[9];
    }
    //Populate with values
    Grid gameGrid;
    gameGrid.populateGameGrid(gameValues, evt.GetId());

    //Create screen
    GameFrame* gameFrame = new GameFrame("Sudoku Application Game Screen", gameValues);

    gameFrame->SetClientSize(600,600);
    gameFrame->Center();
    gameFrame->Show();

}
