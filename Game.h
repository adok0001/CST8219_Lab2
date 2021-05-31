/**
* Name: Adokeme Tamara
* Student Number: 040873188
**/

#include <iostream>
#include <vector>
using namespace std;
const double NO_TIMEOUT(-1);

namespace CST8219 {
	class Game {
	private:
		string name;
		int numPlayers;
		double timeout;

	public:
		Game(string name, int nPlayers, double duration) {
			this->name = name;
			numPlayers = nPlayers;
			timeout = duration;
		}
		Game(string name, int nPlayers) {
			this->name = name;
			numPlayers = nPlayers;
			timeout = NO_TIMEOUT;
		}
		Game(string name):Game(name, 1) {
			timeout = NO_TIMEOUT;
		}
		Game():Game("[NoName]") {}

		void printGame();

		Game createOneGame(Game g) {

			while (true) {
				cout << "Enter the name: " << endl;
				cin >> name;
				if (name.empty()) {
					cout << "Name cannot be empty" << endl;
					cin.clear();
				}
				else break;
			}

			while (true) {
				cout << "Enter the number of players" << endl;
				cin >> numPlayers;
				if (numPlayers < 1 || numPlayers > 10) {
					cin.clear();
					cout << "Number of players must be between 1-10 " << endl;
				}
				else
					break;
			}
			while (true) {
				cout << "Enter the game duration" << endl;
				cin >> timeout;
				if (timeout <= 0) {
					cin.clear();
					cout << "Timeout cannot be a negative number\n";
				}
				else
					break;

			}

			Game aGame = Game(name, numPlayers, timeout);
			aGame.printGame();
			return aGame;
		}

		void Game::createMultipleGames(vector<Game> gameList) {

			int i, n;


			cout << "Enter number of games to be created: " << endl;
			cin >> n;

			for (i = 0; i < n; i++) {
				Game newGame = Game();
				gameList.push_back(newGame.createOneGame(newGame));
			}

			for (i = 0; i < n; i++) {
				gameList.at(i).printGame();
			}
		}

	
	};
}



