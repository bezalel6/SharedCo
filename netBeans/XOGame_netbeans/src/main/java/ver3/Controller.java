package ver3;

import javax.swing.*;
import java.awt.*;

public class Controller
{
    private static int ROWS = 3, COLS = 3;
    private static View view = new View(ROWS,COLS);
    private static Model model = new Model(ROWS,COLS);


    public static void main(String[] args)
    {
        model.initGame();
        view.createGUI();
        view.LoadAssets();

    }
    
    public static char getPlayer(){return model.getPlayer();}
    public static void newGame()
    {
         // 1. ניקוי הלוח
         model.cleanBoard();
         view.cleanBoard();
    }
    // בעת לחיצה על כפתור תזומן פעולה זו
    public static void buttonClicked(Location loc)
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

}
