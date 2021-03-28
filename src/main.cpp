#include <ChessBoard.h>

#include <list>

using namespace std;

int main()
{
    ChessBoard Board;
    string input;
    list<string> notations;
    while (true) {
        cin >> input;
        cin >> input;
        if (input.find('#') != string::npos)
            break;
        notations.push_front(input);
        if (input.find('#') != string::npos)
            break;
        cin >> input;
        notations.push_front(input);
        if (input.find('#') != string::npos)
            break;
    }
    cout << endl;
    Board.visualize_board();
    cout << endl;
    int i = 0;
    while (notations.size() != 0) {
        i++;
        try {
            Board.do_chess_notation(*(--notations.end()));
        } catch (const char* what_hapenned) {
            cout << endl
                 << *(--notations.end()) << endl
                 << "Error: " << what_hapenned << endl
                 << "move: " << i / 2 + 1 << endl;
            return 1;
        }
        cout << i / 2 + 1 << '.' << *(--notations.end()) << endl << endl;
        Board.visualize_board();
        cout << endl << endl;
        notations.pop_back();
    }
    return 0;
}
