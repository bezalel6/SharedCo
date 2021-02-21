package ver3_MVC;

import java.util.ArrayList;
import java.util.Random;

/**
 * Controller - XO Game Main Controller
 * 26/1/2021
 * By Ilan Peretz (ilanperets@gmail.com).
 */
public class Controller 
{
    // Constants - קבועים
    public static final int DEFAULT_BOARD_SIZE = 3;
    
    // Fields - תכונות
    private Model model;  // מודל
    private View view;    // תצוגה
    private char currentPlayer; // סימן השחקן הנוכחי זה שתורו לשחק כעת

    /**
     * יצירת המשחק פעם יחידה בלבד
     */
    public Controller()
    {
        // Load assets...
        
        // Create the game Model & View
        model = new Model(DEFAULT_BOARD_SIZE);
        view = new View(DEFAULT_BOARD_SIZE, this);
    }
    
     /**
     * New Game setup.
     * called every time new game started
     */
    public void startNewGame()
    {
        currentPlayer = 'X';
        
        model.setup();  // לוח משחק לוגי למצב התחלת משחק
        view.setup();   // לוח משחק תצוגה למצב התחלת משחק
        
        System.out.println(model);
    }
    
    public void resetModel()
    {
        model.setup();
    }
    // btnNewGame פעולה זו מזומנת על ידי התצוגה בעת לחיצה על כפתור
    // לצורך ביצוע התחלת משחק חדש
    public void newGameButtonPressed()
    {
        System.out.println("newGameButtonPressed");
        startNewGame();
    }
     
    // btnAIMoveפעולה זו מזומנת על ידי התצוגה בעת לחיצה על כפתור 
    // לצורך ביצוע מהלך של שחקן ממוחשב
    public void aiMoveButtonPressed()
    {
        System.out.println("aiMoveButtonPressed");
        Location loc = model.getAiMove();
        model.makeMove(loc,currentPlayer);
        System.out.println(model);
        view.updateBoardButton(loc, currentPlayer);
        
        checkGameStatus();
    }
    
    // פעולה זו מזומנת על ידי התצוגה בעת לחיצה על אחד מכפתורי לוח המשחק
    // לצורך ביצוע מהלך של שחקן אנושי
    public void boardButtonPressed(Location loc)
    {
        System.out.println("boardButtonPressed loc="+loc);
        
        // update model - שם את סימן השחקן הנוכחי במיקום שקיבלת
        model.makeMove(loc, currentPlayer);
        System.out.println(model);
        
        // update view - שים בכפתור הלוח במיקום שהתקבל את סימן השחקן
        view.updateBoardButton(loc, currentPlayer);
        
        checkGameStatus();
    }
    
 
    // הפעולה בודקת את מצב המשחק
    // האם המשחק ניגמר בניצחון או תיקו
    // אם המשחק לא ניגמר אז מבצעים החלפת תור שחקן
    private void checkGameStatus()
    {
        System.out.print(">> checkGameStatus: ");

        //1. נבדוק האם יש ניצחון לשחקן הנוכחי זה ששיחק כעת
        // =============================================
        ArrayList<Location> winLocs = model.checkWin(currentPlayer);
        if (winLocs != null)
        {
            String msg = "Game Over - " + currentPlayer + " Win!";
            System.out.println(msg);
            view.gameOver(msg, winLocs);
            return;
        }

        //2. נבדוק האם יש תיקו כלומר נגמר המשחק ואף אחד לא ניצח
        // ====================================================
        if (model.checkTie() == true)
        {
            String msg = "Game Over - Tie!";
            System.out.println(msg);
            view.gameOver(msg, null);
            return;
        }

        //3. אין ניצחון ואין תיקו מחליפים תור וממשיכים לשחק
        // ====================================================
        switchTurn();
    }
    
    private void switchTurn()
    {
        System.out.println("switch players & continue to play...");
        
        // החלפת סימן שחקן תור מתחלף
        if (currentPlayer == 'X')
            currentPlayer = 'O';
        else
            currentPlayer = 'X';
        
        view.setLableMsg(currentPlayer + " Turn");
    }
     
    // פעולה ראשית
    public static void main(String[] args)
    {
        Controller game = new Controller();
        game.startNewGame();
    }

   
}
