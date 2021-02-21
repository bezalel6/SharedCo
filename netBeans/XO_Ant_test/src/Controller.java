

import java.awt.*;

public class Controller
{
    public static final int ROWS = 3, COLS = 3;
    private View view;
    private Model model;

    public Controller() {
        view = new View(ROWS,COLS,this);
        model = new Model(ROWS,COLS);

    }
    
    public void run()
    {
        model.initGame();
        model.cleanBoard();
        view.createGUI();
        view.LoadAssets();
    }

    public char getPlayer(){return model.getPlayer();}
    public void newGame()
    {
         // 1. ניקוי הלוח
         model.cleanBoard();
         view.cleanBoard();
    }
    // בעת לחיצה על כפתור תזומן פעולה זו
    public void buttonClicked(Location loc)
    {
        System.out.println(">> buttonClicked");

        //? האם המשחק ניגמר
        char check = model.buttonClicked(loc);
        switch (check){
            case 'T':{view.tie();break;}
            case ' ':{view.nextTurn(model.getPlayer());break;}
            default:view.win(check,model.getWinLocs());
        }
    }
    public static void main(String[] args)
    {
        Controller c = new Controller();
        c.run();
    }
}
