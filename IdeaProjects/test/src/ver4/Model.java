package ver4;

import javax.swing.*;
import java.util.ArrayList;

public class Model {


    //
    static JButton[][] btnMat;  // מטריצת הכפתורים
    public char player;         // סימן השחקן שתורו לשחק כעת
    private static int ROWS = Controller.ROWS;
    private static int COLS = Controller.COLS;
    public Model(int ROWS, int COLS) {
        this.ROWS = ROWS;
        this.COLS = COLS;
    }
    public void initGame()
    {
        player = 'X';

        btnMat = new JButton[ROWS][COLS];


        // לולאה שעוברת על כל השורות במטריצה
        for(int row = 0; row < ROWS; row++)
        {
            // לולאה שעוברת על כל העמודות
            for(int col = 0; col < COLS; col++)
            {
                // יצירת כפתור בלוח המשחק
                btnMat[row][col] = new JButton(" "); //new JButton(row+","+col);

            }
    }}
    // בעת לחיצה על כפתור תזומן פעולה זו
    public char buttonClicked(Location loc)
    {
        // סימן השחקן על הכפתור
        JButton btn = convertLocToBtn(loc);
        btn.setText(player + "");

        // נעילת הכפתור
        btn.setEnabled(false);

        //? האם המשחק ניגמר
        char check = checkGameStatus();
        if(check==' ')
            // החלפת סימן שחקן תור מתחלף
            changeTurn();
        return check;
    }
    public void cleanBoard()
    {
        for(int row=0; row < ROWS; row++)
        {
            for(int col=0; col < COLS; col++)
            {
                btnMat[row][col].setText(" ");
                btnMat[row][col].setBackground(null);
            }
        }
        // 3. שחקן מתחיל והודעה
        initGame();
    }

    // בדיקת ניצחון
    static ArrayList<Location> winLocList = new ArrayList();
    public ArrayList<Location> checkWin(char player)
    {
        // רשימת מיקומי


        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהשורות
        for (int row = 0; row < ROWS; row++)
        {
            winLocList.clear();
            for (int col = 0; col < COLS; col++)
            {
                if (btnMat[row][col].getText().charAt(0) != player)
                    break;
                else
                    winLocList.add(new Location(row, col));
            }
            if (winLocList.size() == ROWS)
                return winLocList;
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באחת מהעמודות
        for (int col = 0; col < COLS; col++)
        {
            winLocList.clear();
            for (int row = 0; row < ROWS; row++)
            {
                if (btnMat[row][col].getText().charAt(0) != player)
                    break;
                else
                    winLocList.add(new Location(row, col));
            }
            if (winLocList.size() == COLS)
                return winLocList;
        }

        // נבדוק האם יש ניצחון לשחקן הנוכחי באלכסון הראשי
        winLocList.clear();
        for (int i = 0; i < ROWS; i++)
        {
            if (btnMat[i][i].getText().charAt(0) != player)
                break;
            else
                winLocList.add(new Location(i, i));
        }
        if (winLocList.size() == ROWS)
            return winLocList;

        // נבדוק האם יש ניצחון לשחקן הנוכחי באלכסון משני
        winLocList.clear();
        for (int i = 0; i < ROWS; i++)
        {
            if (btnMat[i][ROWS - i - 1].getText().charAt(0) != player)
                break;
            else
                winLocList.add(new Location(i, ROWS - i - 1));
        }
        if (winLocList.size() == ROWS)
            return winLocList;

        // אם הגענו לכאן לא נמצא ניצחון בלוח
        return null;
    }
    private static JButton convertLocToBtn(Location loc)
    {
        return btnMat[loc.getRow()][loc.getCol()];
    }
    /**
     * הפעולה בודקת האם המשחק ניגמר
     * @return 'X' if x won, or 'O' if player o won, or 'T' if Tie, or ' ' game not over
     */
    ArrayList<Location> getWinLocs(){
        return winLocList;
    }
    public char checkGameStatus()
    {
        System.out.print(">> checkGameStatus: ");

        //1. נבדוק האם יש ניצחון לשחקן הנוכחי זה ששיחק כעת
        // =============================================
        ArrayList<Location> winLocs = checkWin(player);
        if(winLocs != null)
        {
            System.out.println(player + " WIN! " + winLocs);
            //view.colorWinLoc(winLocs);
            return player;
        }


        //2. נבדוק האם יש תיקו כלומר נגמר המשחק ואף אחד לא ניצח
        // ====================================================
        boolean isTie = true;
        for(int row = 0; row < ROWS; row++)
        {
            for(int col = 0; col < COLS; col++)
            {
                if(btnMat[row][col].getText().equals(" "))
                    isTie = false;
            }
        }
        if(isTie == true)
        {
            System.out.println("TIE - No Winners!");
            return 'T';
        }
        //3. אין ניצחון ואין תיקו המשחק ממשיך
        // ====================================================
        System.out.println("continue to play...");
        return ' ';
    }
    public void changeTurn()
    {
        if (player == 'X') player = 'O';
        else player = 'X';
    }

}
