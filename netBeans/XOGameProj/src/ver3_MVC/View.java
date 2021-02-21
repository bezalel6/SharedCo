package ver3_MVC;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FileDialog;
import java.io.FileFilter;
import java.awt.Font;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Image;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.FilenameFilter;
import java.util.ArrayList;
import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JColorChooser;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

/**
 * View - XO Game GUI 26/1/2021 By Ilan Peretz (ilanperets@gmail.com).
 */
public class View {

    // קבועים
    public static final String WIN_TITLE = "XO Game (ver3_MVC)";
    public static final Font FONT1 = new Font(null, Font.BOLD, 60);  // פונט לכפתורים
    public static final Font FONT2 = new Font(null, Font.BOLD, 16);  // פונט לכפתורים
    private static final int settingsIconSize = 20;
    private static int ROWS;  // מספר השורות במטריצה
    private static int COLS;  // מספר העמודות במטריצה

    // משתנים 
    private JFrame win, settingsWin;
    private JButton btnNewGame, btnAIMove;
    private JLabel lblMsg;       // תוית להצגת תור מי לשחק
    private JButton[][] btnMat;  // מטריצת הכפתורים
    private Controller controller;
    private ImageIcon x, o, settingsIcon;
    private JButton changeX, changeO, resetSelection, selectBackgroundColor;
    private Color backColor = Color.WHITE, defaultBackColor = Color.WHITE;

    public View(int boardSize, Controller controller) {
        // Load assets...
        ROWS = boardSize;
        COLS = boardSize;

        this.controller = controller;

        // Create GUI...
        createGUI();
    }

    public void setup() {
        for (int row = 0; row < ROWS; row++) {
            // לולאה שעוברת על כל העמודות
            for (int col = 0; col < COLS; col++) {
                btnMat[row][col].setText(" ");
                btnMat[row][col].setIcon(null);
                btnMat[row][col].setDisabledIcon(null);
                btnMat[row][col].setEnabled(true);
                btnMat[row][col].setBackground(backColor);
            }
        }
        controller.resetModel();
        
        changeX.setIcon(x);
        changeO.setIcon(o);
        
        btnNewGame.setEnabled(false);
        btnAIMove.setEnabled(true);
        lblMsg.setText("X Turn");
        lblMsg.setBackground(null);
    }

    // פעולה היוצרת את הממשק הגרפי של המשחק
    private void createGUI() {
        loadAssets();

        settingsWin = new JFrame("Settings");
        settingsWin.setSize(600, 200);
        changeX = new JButton("Change X logo");
        changeO = new JButton("Change O logo");
        resetSelection = new JButton("Reset Selection");
        selectBackgroundColor = new JButton("Select Background Color");
        settingsWin.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        changeX.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                setIcon('X');

            }
        });
        changeO.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                setIcon('O');

            }
        });
        resetSelection.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                resetImages();

            }
        });
        selectBackgroundColor.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                changeBackgroundColor();

            }

        });

        resetSelection.setFocusable(false);
        changeX.setFocusable(false);
        changeO.setFocusable(false);
        selectBackgroundColor.setFocusable(false);

        changeX.setFont(FONT2);
        changeO.setFont(FONT2);
        resetSelection.setFont(FONT2);
        selectBackgroundColor.setFont(FONT2);

        settingsWin.add(changeX);

        settingsWin.add(changeO);

        settingsWin.add(resetSelection);
        settingsWin.add(selectBackgroundColor);
        settingsWin.setLayout(new GridLayout(2, 2));
        settingsWin.setLocationRelativeTo(null);
        settingsWin.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        // יצירת החלון למחשבון
        win = new JFrame(WIN_TITLE);
        win.setSize(400, 400);
        win.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        // יצירת פאנל עליון לכפתורי ניהול המשחק
        JPanel pnlTop = new JPanel();
        pnlTop.setBorder(BorderFactory.createEmptyBorder(8, 8, 8, 8));

        // כפתור להתחלת משחק חדש
        btnNewGame = new JButton("New Game");
        btnNewGame.setFocusable(false);
        btnNewGame.setForeground(Color.BLUE);
        btnNewGame.setFont(FONT2);
        btnNewGame.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                controller.newGameButtonPressed();
            }
        });
        pnlTop.add(btnNewGame);

        // כפתור לשחקן ממוחשב
        btnAIMove = new JButton("AI Move");
        btnAIMove.setFocusable(false);
        btnAIMove.setForeground(Color.BLUE);
        btnAIMove.setFont(FONT2);
        btnAIMove.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                // TODO: tell to controller that btnAI button, pressed!
                controller.aiMoveButtonPressed();
            }
        });
        pnlTop.add(btnAIMove);

        // יצירת פאנל לכפתורים
        JPanel pnlButtons = new JPanel();
        pnlButtons.setLayout(new GridLayout(ROWS, COLS));

        // מערך הכפתורים של המחשבון
        btnMat = new JButton[ROWS][COLS];

        // יצירת כל כפתורי המחשבון קביעת הפונט שלהם והוספתם לחלון על פי גריד שנקבע
        // לולאה שעוברת על כל השורות במטריצה
        for (int row = 0; row < ROWS; row++) {
            // לולאה שעוברת על כל העמודות
            for (int col = 0; col < COLS; col++) {
                // יצירת כפתור בלוח המשחק
                btnMat[row][col] = new JButton(" ");
                btnMat[row][col].setFont(FONT1);
                btnMat[row][col].setFocusable(false);
                btnMat[row][col].setActionCommand(row + "," + col); // save indexs (row,col)

                // הוספת מאזין לאירוע לחיצה על הכפתור
                btnMat[row][col].addActionListener(new ActionListener() {
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        // Tell to Controller that Board Button was pressed!
                        JButton btn = (JButton) e.getSource();
                        String indexs = btn.getActionCommand(); // get indexes (row,col)
                        int row = Integer.parseInt(indexs.substring(0, indexs.indexOf(',')));
                        int col = Integer.parseInt(indexs.substring(indexs.indexOf(',') + 1));

                        controller.boardButtonPressed(new Location(row, col));
                    }
                });

                // הוספת הכפתור לגריד שבפנאל
                pnlButtons.add(btnMat[row][col]);
            }
        }

        JButton options = new JButton();

        options.setIcon(settingsIcon);
        options.setFocusable(false);
        options.setForeground(Color.BLUE);
        options.setFont(FONT2);
        options.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                // TODO: tell to controller that btnAI button, pressed!
                settingsButtonPressed();

            }
        });

        pnlTop.add(btnAIMove);
        pnlTop.add(options);

        lblMsg = new JLabel("?");
        lblMsg.setBorder(BorderFactory.createEmptyBorder(2, 5, 2, 2));
        lblMsg.setOpaque(true);
        lblMsg.setFont(FONT2);

        // הוספת כפתור לתחילת משחק חדש לצפון החלון
        win.add(pnlTop, BorderLayout.NORTH);

        // הוספת הפאנל למרכז החלון
        win.add(pnlButtons, BorderLayout.CENTER);

        // הוספת התוית לדרום החלון
        win.add(lblMsg, BorderLayout.SOUTH);

        // מרכז החלון
        win.setLocationRelativeTo(null);

        // מציג את החלון על המסך
        win.setVisible(true);
    }

    public void updateBoardButton(Location loc, char player) {
        if (player == 'X') {
            if (x == null) {
                btnMat[loc.getRow()][loc.getCol()].setText(player + "");
            } else {
                btnMat[loc.getRow()][loc.getCol()].setDisabledIcon(x);
                btnMat[loc.getRow()][loc.getCol()].setIcon(x);
            }
        } else {
            if (o == null) {
                btnMat[loc.getRow()][loc.getCol()].setText(player + "");
            } else {
                btnMat[loc.getRow()][loc.getCol()].setDisabledIcon(o);
                btnMat[loc.getRow()][loc.getCol()].setIcon(o);
            }
        }
        btnMat[loc.getRow()][loc.getCol()].setEnabled(false);

    }

    public void gameOver(String msg, ArrayList<Location> winLocs) {
        // lock all board buttons
        setBoardButtonsEnabled(false);
        btnNewGame.setEnabled(true);
        btnAIMove.setEnabled(false);

        lblMsg.setText(msg);
        lblMsg.setBackground(Color.GREEN);

        if (winLocs != null) {
            colorWinLoc(winLocs);
        }
    }

    // פעולה לנעילה או פתיחה של כל כפתורי הלוח על פי הפרמטר שמתקבל
    // status=true - נעילה
    // status=false - פתיחה
    private void setBoardButtonsEnabled(boolean status) {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                btnMat[row][col].setEnabled(status);
            }
        }
    }

    // פעולה שצובעת את מיקום הניצחון
    private void colorWinLoc(ArrayList<Location> winLocList) {
        for (int i = 0; i < winLocList.size(); i++) {
            Location loc = winLocList.get(i);
            btnMat[loc.getRow()][loc.getCol()].setBackground(Color.YELLOW);
        }
    }

    private void setIcon(char btn) {
        FileDialog dialog = new FileDialog((Frame) null, "Select File to Open");
        //dialog.setDefaultCloseOperation(FileDialog.ABORT);
        dialog.setMode(FileDialog.LOAD);
        dialog.setFile("*.png");//dialog.setFile("*.jpg;*.jpeg");
        dialog.setVisible(true);
        String file = dialog.getDirectory() + "" + dialog.getFile();

        System.out.println(file + " chosen.");
        ImageIcon img = new ImageIcon(file);
        img = new ImageIcon(img.getImage().getScaledInstance(50, 50, Image.SCALE_SMOOTH));
        if (btn == 'X') {
            changeX.setIcon(img);
            x = img;
        } else {
            changeO.setIcon(img);
            o = img;
        }
        dialog.dispose();
    }

    private void resetImages() {
        if (!askUser("Reseting the selections will reset the game.")) {
            return;
        }
        x = null;
        o = null;
        changeX.setIcon(null);
        changeO.setIcon(null);
        backColor = defaultBackColor;
        setup();
    }

    private void settingsButtonPressed() {
        settingsWin.setVisible(true);
    }

    public void setLableMsg(String msg) {
        lblMsg.setText(msg);
    }

    private boolean askUser(String message) {
        return JOptionPane.YES_OPTION == JOptionPane.showConfirmDialog(null, message + "\ndo you want to continue?", "Attention", JOptionPane.YES_NO_OPTION);
    }

    private void changeBackgroundColor() {
        if (!askUser("Changing the background color will reset the game.")) {
            return;
        }

        backColor = JColorChooser.showDialog(null, "Choose a color", backColor);
        setup();
    }

    private void loadAssets() {
        settingsIcon = new ImageIcon(View.class.getResource("/assets/settings_icon.png"));
        settingsIcon = new ImageIcon(settingsIcon.getImage().getScaledInstance(settingsIconSize, settingsIconSize, Image.SCALE_SMOOTH));
    }
}
