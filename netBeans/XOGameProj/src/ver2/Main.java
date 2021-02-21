package ver2;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.BorderFactory;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * XO Game (ver2) - המשחק איקס עיגול גירסה שנייה.
 * 17/11/2020
 * By Ilan Peretz (ilanperets@gmail.com)
 */
public class Main
{
    // קבועים
    static final String WIN_TITLE = "XO Game (ver2)";
    static final int BUTTON_SIZE = 100;  // ממדי הכפתור בלוח המשחק
    static final Font FONT1 = new Font(null, Font.BOLD, 60); // פונט לכפתורי המשחק
    static final Font FONT2 = new Font(null, Font.BOLD, 20); // פונט לכפתורי המשחק
    static final int ROWS = 3;  // מספר השורות במטריצה
    static final int COLS = 3;  // מספר העמודות במטריצה

    //
    static JButton btnNewGame;
    static JLabel lblTurn;      // תוית להצגת תור מי לשחק
    static JButton[][] btnMat;  // מטריצת הכפתורים
    static char player;         // סימן השחקן שתורו לשחק כעת

    public static void main(String[] args)
    {
        initGame();
        createGUI();  
    }

    private static void initGame()
    {
        player = 'X';
    }

    // פעולה היוצרת את הממשק הגרפי של המשחק
    private static void createGUI()
    {
        // יצירת החלון למחשבון
        JFrame win = new JFrame(WIN_TITLE);
        win.setSize(500, 500);
        win.setLocationRelativeTo(null);
        win.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        // מערך הכפתורים של המחשבון
        btnMat = new JButton[ROWS][COLS];

        // יצירת פאנל לכפתורים
        JPanel pnlButtons = new JPanel();
        pnlButtons.setLayout(new GridLayout(ROWS, COLS));

        // יצירת כל כפתורי המחשבון קביעת הפונט שלהם והוספתם לחלון על פי גריד שנקבע
        // לולאה שעוברת על כל השורות במטריצה
        for(int row = 0; row < ROWS; row++)
        {
            // לולאה שעוברת על כל העמודות
            for(int col = 0; col < COLS; col++)
            {
                // יצירת כפתור בלוח המשחק
                btnMat[row][col] = new JButton(" "); //new JButton(row+","+col);
                btnMat[row][col].setFont(FONT1);
                btnMat[row][col].setFocusable(false);
                
                // הוספת מאזין לאירוע לחיצה על הכפתור
                btnMat[row][col].addActionListener(new ActionListener()
                {
                    @Override
                    public void actionPerformed(ActionEvent e)
                    {
                        // תן לי את הכפתור שנילחץ כעת
                        JButton btn = (JButton) e.getSource();
                        buttonClicked(btn);
                    }
                });

                // הוספת הכפתור לגריד שבפנאל
                pnlButtons.add(btnMat[row][col]);
            }
        }

        JPanel pnlTop = new JPanel();
        
        // כפתור להתחלת משחק חדש
        btnNewGame = new JButton("New Game");
        btnNewGame.setFocusable(false);
        btnNewGame.setForeground(Color.BLUE);
        btnNewGame.setFont(FONT2);
        btnNewGame.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae)
            {
                newGame();
            }
        });
        pnlTop.add(btnNewGame);
        
        lblTurn = new JLabel(player + " Turn");
        lblTurn.setBorder(BorderFactory.createEmptyBorder(2,5,2,2));
        lblTurn.setOpaque(true);
        lblTurn.setFont(FONT2);

        // הוספת כפתור לתחילת משחק חדש לצפון החלון
        win.add(pnlTop, BorderLayout.NORTH);
        
        // הוספת הפאנל למרכז החלון
        win.add(pnlButtons, BorderLayout.CENTER);
        
        // הוספת התוית לדרום החלון
        win.add(lblTurn, BorderLayout.SOUTH);

        // מציג את החלון על המסך
        win.setVisible(true);
    }

    // בעת לחיצה על כפתור תזומן פעולה זו
    public static void buttonClicked(JButton btn)
    {
        System.out.println(">> buttonClicked");
        
        // סימן השחקן על הכפתור
        btn.setText(player + "");
        
        // נעילת הכפתור
        btn.setEnabled(false);
        
        //? האם המשחק ניגמר
        char check = checkGameStatus();
        
        if(check != ' ')  //? האם המשחק נגמר
        {
            // נעילת הכפתורים
            enableAllButtons(false);
            
            // האם נגמר בניצחון או תיקו
            if(check == 'T')
                lblTurn.setText("Game Over - Tie!");
            else
            {
                lblTurn.setText("Game Over - "+check+" Win!");
                //btn.setBackground(Color.YELLOW);
            }
        }
        else
        {
            // החלפת סימן שחקן תור מתחלף
            if(player == 'X')
            {
                player = 'O';
            }
            else
            {
                player = 'X';
            }
            lblTurn.setText(player + " Turn");
        }
    }
    
    // בדיקת ניצחון
    public static ArrayList<Location> checkWin(char player)
    {
        // רשימת מיקומי 
        ArrayList<Location> winLocList = new ArrayList();

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
    
    /**
     * הפעולה בודקת האם המשחק ניגמר
     * @return 'X' if x won, or 'O' if player o won, or 'T' if Tie, or ' ' game not over
     */
    public static char checkGameStatus()
    {
        System.out.print(">> checkGameStatus: ");
        
        //1. נבדוק האם יש ניצחון לשחקן הנוכחי זה ששיחק כעת
        // =============================================
        ArrayList<Location> winLocs = checkWin(player);
        if(winLocs != null)
        {
            System.out.println(player + " WIN! " + winLocs);
            colorWinLoc(winLocs);
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

    // נעילת כל הכפתורים
    private static void enableAllButtons(boolean status)
    {
        for(int row= 0; row < ROWS; row++)        
        {
            for(int col= 0; col < COLS; col++)            
            {
                btnMat[row][col].setEnabled(status);
            }
        }
    }
    
    
    // נעילת כל הכפתורים
    private static void cleanBoard()
    {
        for(int row=0; row < ROWS; row++)        
        {
            for(int col=0; col < COLS; col++)            
            {
                btnMat[row][col].setText(" ");
                btnMat[row][col].setBackground(null);
            }
        }
    }
   
    private static void newGame()
    {
         // 1. ניקוי הלוח
         cleanBoard();
         
         // 2. לפתוח נעילות כפתורים
         enableAllButtons(true);
         
         // 3. שחקן מתחיל והודעה
         player = 'X';
         
         lblTurn.setText(player + " Turn");
    }

//    private static void colorWinLoc(Location[] locArr, Color color)
//    {
//        for(int i= 0; i < locArr.length; i++)        
//        {
//            Location loc = locArr[i];
//            btnMat[loc.getRow()][loc.getCol()].setBackground(color);
//        }
//    }
    
    private static void colorWinLoc(ArrayList<Location> winLocList)
    {
        for(int i= 0; i < winLocList.size(); i++)        
        {
            Location loc = winLocList.get(i);
            btnMat[loc.getRow()][loc.getCol()].setBackground(Color.YELLOW);
        }
    }
}
