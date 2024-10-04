
#ifndef GAME_FRAME_H_INCLUDED
#define GAME_FRAME_H_INCLUDED
#endif // GAME_FRAME_H_INCLUDED
#include <wx/wx.h>
#include <wx/grid.h>

class GameFrame : public wxFrame, public wxGridTableBase
{
public:
    GameFrame(const wxString& title, int** InputGrid);

private:
    void OnCellChanging(wxGridEvent& evt);
    void OnCellValidate(wxGridEvent& evt);
    void InitializeValues(int** grid, wxGrid* gameBoard);
    void CreateGrid();
    void DrawGrid(int** gridValues);
    void SetGridState(int** gridValues);
    int** GetGridState() const;
    int** gridValues;
    wxGrid* sudokuGrid;
    wxPanel* panel;
    wxGrid* GetGameBoardState() const;
    wxDECLARE_EVENT_TABLE();

};

