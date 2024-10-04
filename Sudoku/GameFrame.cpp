#include "GameFrame.h"
#include "GameGrid.h"
#include "BasicDrawPane.h"
#include <wx/wx.h>
#include <wx/grid.h>
#include <string>
#include <iostream>

using namespace std;

//Class variables for inputs, validation, and drawing
int** grid;
wxGrid* sudokuGrid;
wxPanel* panel;
//Integer which is set by incoming event value of EVT_GRID_CELL_CHANGING
int ValueUnderConsideration = -1;
//Event table for binding events to grid behavior
wxBEGIN_EVENT_TABLE(GameFrame, wxFrame)
    EVT_GRID_CELL_CHANGING(GameFrame::OnCellChanging)
    EVT_GRID_CELL_CHANGE(GameFrame::OnCellValidate)
    EVT_GRID_CELL_CHANGED(GameFrame::OnCellValidate)
wxEND_EVENT_TABLE()


void GameFrame::SetGridState(int** newGrid){

    grid = newGrid;
}

int** GameFrame::GetGridState() const{

    return grid;
}

wxGrid* GameFrame::GetGameBoardState() const{
    return sudokuGrid;
}



//Initialization of Game Frame
GameFrame::GameFrame(const wxString& title, int** InputGrid): wxFrame(nullptr, wxID_ANY, title), wxGridTableBase(){

 //Set class grid to input grid
 grid = InputGrid;
 //Set up grid visually and apply values to cells
 DrawGrid(grid);

}

//Catches event before cell has been altered

void GameFrame::OnCellChanging(wxGridEvent& event){
    //Retrieve event string and parse as integer for validation/entry
    wxString IncomingValue = event.GetString();
    std::string ValueAsNormalString = IncomingValue.ToStdString();
    int ValueAsInteger = std::stoi(ValueAsNormalString);
    ValueUnderConsideration = ValueAsInteger;
}
//Handles actual changing of grid
void GameFrame::OnCellValidate(wxGridEvent& event){

    //Get pointer to grid values in array and wxGrid object being displayed
    wxGrid* thisGrid = GetGameBoardState();
    int** GameValues = GetGridState();

    //Create Grid object for access to GameGrid methods
    Grid GridObject;
    //Check if incoming change is a valid one
    if(GridObject.checkValidEntry(GameValues, event.GetRow(), event.GetCol(),  ValueUnderConsideration)){
        //If it is valid, change value in local copy of grid and then set as state
        GameValues[event.GetCol()][event.GetRow()] = ValueUnderConsideration;
        SetGridState(GameValues);
    }

    //Prepare grid to be re-rendered
    thisGrid->ClearGrid();
    InitializeValues(GameValues, thisGrid);
    thisGrid->ForceRefresh();

}
//Iterate through array and set cell values
void GameFrame::InitializeValues(int** Grid, wxGrid* GameBoard){


for(int i = 0; i < 9; i++){

    for(int j = 0; j < 9; j++){

        if(Grid[j][i] == 0){
        GameBoard->SetCellValue(wxGridCellCoords(i, j), "");
        }
        else{
        GameBoard->SetCellValue(wxGridCellCoords(i, j), std::to_string(grid[j][i]));
        }

    }

 }



}
//Set up dimensions and appearance of game grid
void GameFrame::DrawGrid(int** Grid){

 panel = new wxPanel(this);
 const wxFont& standardFont = wxFont(wxFontInfo(16).FaceName("Helvetica").Bold());

 sudokuGrid = new wxGrid(panel, -1, wxPoint(0,0), wxSize(600,600));
 sudokuGrid->CreateGrid(9,9);
 sudokuGrid->HideRowLabels();
 sudokuGrid->HideColLabels();

 for(int i = 0; i < 9; i++){
    sudokuGrid->SetColSize(i, 40);
    sudokuGrid->SetRowSize(i, 40);
    for(int j = 0; j < 9; j++){
    sudokuGrid->SetCellAlignment(i, j, wxALIGN_CENTRE, wxALIGN_CENTER);
    sudokuGrid->SetCellFont(i, j, standardFont);

    }
 }

 InitializeValues(Grid, sudokuGrid);


}




