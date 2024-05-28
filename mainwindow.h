#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Observer.h"
#include "Room.h"
#include "GameState.h"
#include "BattleHandler.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

QT_END_NAMESPACE
using namespace std;


class MainWindow : public QMainWindow, public Observer
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    GameState state;
    BattleHandler* battleHandler;

    void changeText(string);
    void continueButton();
    void northButton();
    void southButton();
    void eastButton();
    void westButton();
    void attackButton();
    void blockButton();

    void updateR(Room*) override;
    void setVisibilityRegUI(bool);
    void setVisibilityBattleUI(bool);
    void validRoomsToMove();
    void renderInventory();
    void equipButton(Item*);
    void updatePlayerHealth();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
