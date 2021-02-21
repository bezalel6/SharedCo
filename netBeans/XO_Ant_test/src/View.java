
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

public class View {

    private final Font FONT1 = new Font(null, Font.BOLD, 60); // פונט לכפתורי המשחק
    private final Font FONT2 = new Font(null, Font.BOLD, 40); // פונט לכפתורי המשחק
    private final String WIN_TITLE = "XO Game (ver3)";
    private final int BUTTON_SIZE = 100; // ממדי הכפתור בלוח המשחק

    private int ROWS, COLS;
    private JPanel pnlTop = new JPanel();
    private ImageIcon o, x;

    private JButton btnNewGame;
    private JLabel lblTurn; // תוית להצגת תור מי לשחק
    private JButton[][] btnMat; // מטריצת הכפתורים

    private double sizeMulti = .7;
    private int iconSize = (int) (BUTTON_SIZE * sizeMulti);

    private Controller controller;

    public View(int ROWS, int COLS, Controller c) {
        controller = c;
        this.ROWS = ROWS;
        this.COLS = COLS;
    }

    // פעולה היוצרת את הממשק הגרפי של המשחק
    public void createGUI() {
        // יצירת החלון למשחק
        JFrame win = new JFrame(WIN_TITLE);

        win.setSize(500, 500);
        win.setLocationRelativeTo(null);
        win.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        // מערך הכפתורים של המשחק
        btnMat = new JButton[ROWS][COLS];
        // יצירת פאנל לכפתורים
        JPanel pnlButtons = new JPanel();
        pnlButtons.setLayout(new GridLayout(ROWS, COLS));
        // יצירת כל כפתורי המשחק קביעת הפונט שלהם והוספתם לחלון על פי גריד שנקבע
        // לולאה שעוברת על כל השורות במטריצה
        for (int row = 0; row < ROWS; row++) {
            // לולאה שעוברת על כל העמודות
            for (int col = 0; col < COLS; col++) {
                // יצירת כפתור בלוח המשחק
                btnMat[row][col] = new JButton(" ");
                btnMat[row][col].setFont(FONT1);
                btnMat[row][col].setFocusable(false);

                // הוספת מאזין לאירוע לחיצה על הכפתור
                btnMat[row][col].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        // תן לי את הכפתור שנילחץ כעת
                        clicked((JButton) e.getSource());
                    }
                });

                // הוספת הכפתור לגריד שבפנאל
                pnlButtons.add(btnMat[row][col]);
            }
        }

        // כפתור להתחלת משחק חדש
        btnNewGame = new JButton("New Game");
        btnNewGame.setFocusable(false);
        btnNewGame.setFont(FONT2);
        btnNewGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                controller.newGame();
            }
        });
        pnlTop.add(btnNewGame);
        lblTurn = new JLabel(controller.getPlayer() + " Turn");
        lblTurn.setBorder(BorderFactory.createEmptyBorder(2, 5, 2, 2));
        lblTurn.setOpaque(true);
        lblTurn.setFont(FONT2);

        // הוספת כפתור לתחילת משחק חדש לצפון החלון
        win.add(pnlTop, BorderLayout.NORTH);

        // הוספת הפאנל למרכז החלון
        win.add(pnlButtons, BorderLayout.CENTER);

        // הוספת התוית לדרום החלון
        win.add(lblTurn, BorderLayout.SOUTH);

        enableAllButtons(false);//עד שהפונקצייה שטוענת את הנכסים מסיימת, אנחנו לא רוצים שיהיה אפשר ללחוץ על הכפתורים

        // מציג את החלון על המסך
        win.setVisible(true);

    }

    /*
        כדי למצוא את המיקום של כפתור מבוקש

     */
    public Location getLocationFromBtn(JButton btn) {
        Location loc = new Location();
        for (int i = 0, row = 0; row < ROWS; row++, i++) {
            for (int j = 0, cell = 0; cell < COLS; cell++, j++) {
                if (btn == btnMat[row][cell]) {
                    loc.setCol(cell);
                    loc.setRow(row);
                }
            }
        }
        return loc;
    }

    /*

     */
    public void clicked(JButton btn) {
        if (controller.getPlayer() == 'X') {
            btn.setIcon(x);
            btn.setDisabledIcon(x);
        } else {
            btn.setIcon(o);
            btn.setDisabledIcon(o);
        }
        btn.setEnabled(false);
        controller.buttonClicked(getLocationFromBtn(btn));
    }

    Color winColor = Color.BLUE;

    public void colorWinLoc(ArrayList< Location> winLocList) {
        for (int i = 0; i < winLocList.size(); i++) {
            Location loc = winLocList.get(i);
            btnMat[loc.getRow()][loc.getCol()].setBackground(winColor);
        }
    }

    // נעילת כל הכפתורים
    public void enableAllButtons(boolean status) {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                btnMat[row][col].setEnabled(status);
            }
        }
    }

    public void setTurnLabel(String s) {
        lblTurn.setText(s);
    }

    public void cleanBoard() {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                btnMat[row][col].setText(" ");
                btnMat[row][col].setBackground(null);
                btnMat[row][col].setIcon(null);
            }
        }
        refreshAssets();
    }

    public void LoadAssets() {
        // טעינת התמונה מתוך הקובץ שנימצא בתקיית הנכסים
        o = new ImageIcon(View.class.getResource("/Assets/O.png"));
        // טעינת התמונה מתוך הקובץ שנימצא בתקיית הנכסים
        x = new ImageIcon(View.class.getResource("/Assets/X.png"));

        // הקטנת התמונה לגודל רצוי
        refreshAssets();
    }

    /*
    התאמת גודל הסמלים בהתאם לגודל החלון
     */
    public void refreshAssets() {
        enableAllButtons(false);
        iconSize = (int) (btnMat[0][0].getSize().height * sizeMulti);
        // הקטנת התמונה לגודל רצוי
        o = new ImageIcon(o.getImage().getScaledInstance((int) (iconSize), (int) (iconSize), Image.SCALE_SMOOTH));
        x = new ImageIcon(x.getImage().getScaledInstance((int) (iconSize), (int) (iconSize), Image.SCALE_SMOOTH));
        enableAllButtons(true);
    }

    public void tie() {
        enableAllButtons(false);
        setTurnLabel("Game Over - Tie!");
    }

    public void win(char check, ArrayList< Location> winLocs) {
        setTurnLabel("Game Over - " + check + " Win!");
        enableAllButtons(false);
        colorWinLoc(winLocs);
    }

    public void nextTurn(char player) {
        setTurnLabel(player + " Turn");
    }

}
