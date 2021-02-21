package ver4;

import javax.swing.*;

/**
 * XO Game (ver2) - המשחק איקס עיגול גירסה שנייה.
 * 17/11/2020
 * By Ilan Peretz (ilanperets@gmail.com)
 */
public class Controller
{

    public static int ROWS = 3;
    public static int COLS = 3;
    static View view = new View(ROWS,COLS);
    static Model model = new Model(ROWS,COLS);
    public static void main(String[] args)
    {
        model.initGame();
        view.createGUI();
        view.LoadAssets();

    }
    public static char getPlayer(){return model.player;}
    public static void newGame()
    {
         // 1. ניקוי הלוח
         model.cleanBoard();
         view.cleanBoard();
    }
    // בעת לחיצה על כפתור תזומן פעולה זו
    public static void buttonClicked(JButton btn)
    {
        System.out.println(">> buttonClicked");
        btn.setEnabled(false);

        Location loc = new Location();
        for (int i = 0,row=0; row<ROWS;row++,i++)
            for (int j = 0,cell=0; cell<COLS;cell++,j++)
                if(btn==view.btnMat[row][cell]) {
                    loc.setCol(cell);
                    loc.setRow(row);
                }
        //? האם המשחק ניגמר
        char check = model.buttonClicked(loc);

        if(check != ' ')  //? האם המשחק נגמר
        {
            // נעילת הכפתורים
            view.enableAllButtons(false);

            // האם נגמר בניצחון או תיקו
            if(check == 'T') {
                view.tie();
            }
            else
            {
                view.colorWinLoc(model.getWinLocs());
                view.win(check);

            }
        }
        else
        {
            view.nextTurn();
        }
    }
    public static void setSize(int size)
    {
        ROWS=size;COLS=size;

    }

}
