package ver1;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 * Main - המשחק איקס עיגול גירסה בסיסית.
 * 10/11/2020
 * By Ilan Peretz (ilanperets@gmail.com)
 */
public class Main
{
    static final int ROWS = 5;  // מספר השורות במטריצה
    static final int COLS = 5;  // מספר העמודות במטריצה

    static JButton btnNewGame;
    static JLabel lblTurn;      // תוית להצגת תור מי לשחק
    static JButton[][] btnMat;  // מטריצת הכפתורים
    static char player;         // סימן השחקן שתורו לשחק כעת

    public static void main(String[] args)
    {
        initGame();
        createGUI();  // יוצר את הממשק הגרפי של המשחק
    }

    private static void initGame()
    {
        player = 'X';
    }

    private static void createGUI()
    {
        // יצירת החלון למחשבון
        JFrame win = new JFrame("XO (Tic Tac Toe)");
        win.setSize(500, 500);
        win.setLocationRelativeTo(null);
        win.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        // סוג הפונט לטקסט שיופיע על הכפתורים
        Font font = new Font("Arial", Font.BOLD, 40);

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
                btnMat[row][col] = new JButton(" "); //new JButton(row+","+col);
                btnMat[row][col].setFont(font);

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

        // כפתור להתחלת משחק חדש
        btnNewGame = new JButton("New Game");
        btnNewGame.setFont(font);
        btnNewGame.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae)
            {
                startNewGame();
            }
        });
        
        lblTurn = new JLabel(player + " Turn");
        lblTurn.setOpaque(true);
        lblTurn.setForeground(Color.BLUE);
        lblTurn.setBackground(Color.CYAN);
        lblTurn.setFont(font);

        // הוספת כפתור לתחילת משחק חדש לצפון החלון
        win.add(btnNewGame, BorderLayout.NORTH);
        
        // הוספת התוית לדרום החלון
        win.add(lblTurn, BorderLayout.SOUTH);

        // הוספת הפאנל למרכז החלון
        win.add(pnlButtons, BorderLayout.CENTER);

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
        char check = checkGameOver();
        
        if(check != ' ')  //? האם המשחק נגמר
        {
            // נעילת הכפתורים
            enableAllButtons(false);
            
            // האם נגמר בניצחון או תיקו
            if(check == 'T')
                lblTurn.setText("Game Over - Tie");
            else
                lblTurn.setText("Game Over - "+check+" Win!");
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
    
    /**
     * הפעולה בודקת האם המשחק ניגמר
     * @return 'X' if x won, or 'O' if player o won, or 'T' if Tie, or ' ' game not over
     */
    public static char checkGameOver()
    {
        //1. נבדוק האם יש ניצחון לשחקן הנוכחי זה ששיחק כעת
        // =============================================
        
        // בדיקת כל השורות
        //-------------------------------------
        // נבדוק האם יש לשחקן ניצחון בשורה הראשונה
        if((btnMat[0][0].getText().charAt(0) == player) &&
           (btnMat[0][1].getText().charAt(0) == player) &&
           (btnMat[0][2].getText().charAt(0) == player) )
            return player;
        
        // נבדוק האם יש לשחקן ניצחון בשורה השנייה
        if((btnMat[1][0].getText().charAt(0) == player) &&
           (btnMat[1][1].getText().charAt(0) == player) &&
           (btnMat[1][2].getText().charAt(0) == player) )
            return player;
        
        // נבדוק האם יש לשחקן ניצחון בשורה השלישית
        if((btnMat[2][0].getText().charAt(0) == player) &&
           (btnMat[2][1].getText().charAt(0) == player) &&
           (btnMat[2][2].getText().charAt(0) == player) )
            return player;
        
        // בדיקת כל העמודות
        //-------------------------------------
        // נבדוק האם יש לשחקן ניצחון עמודה הראשונה
        if((btnMat[0][0].getText().charAt(0) == player) &&
           (btnMat[1][0].getText().charAt(0) == player) &&
           (btnMat[2][0].getText().charAt(0) == player) )
            return player;
        
        // נבדוק האם יש לשחקן ניצחון עמודה השנייה
        if((btnMat[0][1].getText().charAt(0) == player) &&
           (btnMat[1][1].getText().charAt(0) == player) &&
           (btnMat[2][1].getText().charAt(0) == player) )
            return player;
        
        // נבדוק האם יש לשחקן ניצחון עמודה השלישית
        if((btnMat[0][2].getText().charAt(0) == player) &&
           (btnMat[1][2].getText().charAt(0) == player) &&
           (btnMat[2][2].getText().charAt(0) == player) )
            return player;
        
        // בדיקת אלכסון ראשי
        //-------------------------------------
        if((btnMat[0][0].getText().charAt(0) == player) &&
           (btnMat[1][1].getText().charAt(0) == player) &&
           (btnMat[2][2].getText().charAt(0) == player) )
            return player;
          
        // בדיקת אלכסון משני
        //-------------------------------------
        if((btnMat[0][2].getText().charAt(0) == player) &&
           (btnMat[1][1].getText().charAt(0) == player) &&
           (btnMat[2][0].getText().charAt(0) == player) )
            return player;
          
        //2. נבדוק האם יש תיקו כלומר נגמר המשחק ואף אחד לא ניצח
        // ====================================================
        boolean isTie = true;
        for(int row= 0; row < ROWS; row++)        
        {
            for(int col= 0; col < COLS; col++)            
            {
                if(btnMat[row][col].getText().equals(" "))
                    isTie = false;
            }
        }
        if(isTie == true)
            return 'T';
        
        //3. אין ניצחון ואין תיקו המשחק ממשיך
        // ====================================================
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
        for(int row= 0; row < ROWS; row++)        
        {
            for(int col= 0; col < COLS; col++)            
            {
                btnMat[row][col].setText(" ");
            }
        }
    }
   
    private static void startNewGame()
    {
         // 1. ניקוי הלוח
         cleanBoard();
         
         // 2. לפתוח נעילות כפתורים
         enableAllButtons(true);
         
         // 3. שחקן מתחיל והודעה
         player = 'X';
         
         lblTurn.setText(player + " Turn");
    }
}
