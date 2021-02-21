package ver4;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;


public class View {
    static int ROWS = Controller.ROWS;
    static int COLS = Controller.COLS;
    public View(int ROWS,int COLS) {
        this.ROWS = ROWS;
        this.COLS = COLS;
    }
    static JPanel pnlTop = new JPanel();
    static JLabel loading = new JLabel("Loading...");

    public static ImageIcon o;
    public static ImageIcon x;
    public static ImageIcon refresh;

    static JButton btnNewGame;
    static JLabel lblTurn;      // תוית להצגת תור מי לשחק
    public static JButton[][] btnMat;  // מטריצת הכפתורים

    static final String WIN_TITLE = "XO Game (ver2)";
    static final int BUTTON_SIZE = 100;  // ממדי הכפתור בלוח המשחק
    private static int iconSize =(int) (BUTTON_SIZE*.7);
    static final Font FONT1 = new Font(null, Font.BOLD, 60); // פונט לכפתורי המשחק
    static final Font FONT2 = new Font(null, Font.BOLD, 40); // פונט לכפתורי המשחק
    // פעולה היוצרת את הממשק הגרפי של המשחק
    public void createGUI()
    {

        refresh = new ImageIcon(Controller.class.getResource("/Assets/refresh.gif"));
        refresh = new ImageIcon(refresh.getImage().getScaledInstance((int)(iconSize), (int)(iconSize), Image.SCALE_FAST));
        setLoading(true);

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
                        clicked(btn);
                    }
                });

                // הוספת הכפתור לגריד שבפנאל
                pnlButtons.add(btnMat[row][col]);
            }
        }
        loading.setIcon(refresh);
        loading.setFont(FONT2);
        setLoading(true);
        pnlTop.add(loading,BorderLayout.EAST);

        JComboBox comboBox = new JComboBox();

        for(int i=3;i<=9;i+=2)
        {
         comboBox.addItem(i);
        }

        comboBox.setFont(FONT2);
        comboBox.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
               char c = e.toString().charAt(0);
               int i=0;
                for( i = 0;i+1<e.toString().length();i++)
                {
                    c = e.toString().charAt(i);
                }
                int num = ((int) c)-((int) '0');
                Controller.setSize(num);
            }
        });

        // כפתור להתחלת משחק חדש
        btnNewGame = new JButton("New Game");
        btnNewGame.setFocusable(false);
        btnNewGame.setFont(FONT2);
        btnNewGame.addActionListener(new ActionListener()
        {
            @Override
            public void actionPerformed(ActionEvent ae)
            {
                setLoading(true);
                Controller.newGame();
            }
        });
        pnlTop.add(btnNewGame);
        pnlTop.add(comboBox);

        lblTurn = new JLabel(Controller.getPlayer() + " Turn");
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
    public void clicked(JButton btn)
    {
        if(Controller.getPlayer()=='X')
        {
            btn.setIcon(x);
            btn.setDisabledIcon(x);
        }
        else
        {
            btn.setIcon(o);
            btn.setDisabledIcon(o);
        }

        Controller.buttonClicked(btn);
    }
    public void colorWinLoc(ArrayList<Location> winLocList)
    {
        for(int i= 0; i < winLocList.size(); i++)
        {
            Location loc = winLocList.get(i);
            btnMat[loc.getRow()][loc.getCol()].setBackground(Color.YELLOW);
        }
    }
    // נעילת כל הכפתורים
    public void enableAllButtons(boolean status)
    {
        for(int row= 0; row < ROWS; row++)
        {
            for(int col= 0; col < COLS; col++)
            {
                btnMat[row][col].setEnabled(status);
            }
        }
    }
    public void setTurnLabel(String s) {lblTurn.setText(s); }
    public void cleanBoard()
    {
        setLoading(true);
        for(int row=0; row < ROWS; row++)
        {
            for(int col=0; col < COLS; col++)
            {
                btnMat[row][col].setText(" ");
                btnMat[row][col].setBackground(null);
                btnMat[row][col].setIcon(null);
            }
        }
        refreshAssets();
    }
    public void LoadAssets()
    {
        setLoading(true);


        // טעינת התמונה מתוך הקובץ שנימצא בתקיית הנכסים
        o = new ImageIcon(Controller.class.getResource("/Assets/O.png"));
        // טעינת התמונה מתוך הקובץ שנימצא בתקיית הנכסים
        x = new ImageIcon(Controller.class.getResource("/Assets/X.png"));
        // טעינת התמונה מתוך הקובץ שנימצא בתקיית הנכסים

        // הקטנת התמונה לגודל רצוי
        refreshAssets();
    }
    public void refreshAssets()
    {
        setLoading(true);
        enableAllButtons(false);
        iconSize = (int)(btnMat[0][0].getSize().height*.7);


        // הקטנת התמונה לגודל רצוי
        o = new ImageIcon(o.getImage().getScaledInstance((int)(iconSize), (int)(iconSize), Image.SCALE_SMOOTH));
        x = new ImageIcon(x.getImage().getScaledInstance((int)(iconSize), (int)(iconSize), Image.SCALE_SMOOTH));
        System.out.println("done loading assets");

        enableAllButtons(true);

        setLoading(false);

    }

    public void tie()
    {
        setTurnLabel("Game Over - Tie!");
    }
    public void win(char check)
    {
        setTurnLabel("Game Over - "+check+" Win!");
    }
    public void nextTurn()
    {
        setTurnLabel(Controller.getPlayer() + " Turn");
    }

    void setLoading(boolean bool)
    {

        loading.setVisible(bool);
        System.out.println("am i visible?"+loading.isVisible());
    }

}
