package loginsyst;

import java.awt.EventQueue;

import javax.swing.ImageIcon;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.LayoutManager;
import java.awt.Button;
import java.awt.TextField;
import javax.swing.JTextField;
import javax.swing.JSeparator;
import javax.swing.JLabel;
import javax.swing.JOptionPane;

import java.awt.Component;
import java.awt.Cursor;
import java.awt.Rectangle;
import javax.swing.JPasswordField;
import java.awt.Font;
import java.awt.Image;
import javax.swing.SwingConstants;
import javax.swing.UIManager;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.StringTokenizer;
import java.awt.event.FocusAdapter;
import java.awt.event.FocusEvent;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;
import javax.swing.JButton;
import javax.swing.border.CompoundBorder;
import javax.swing.border.MatteBorder;
import javax.swing.border.BevelBorder;
import javax.swing.border.TitledBorder;
import javax.swing.border.SoftBevelBorder;

public class loginsyst {
	
	private Image img_logo = new ImageIcon(loginsyst.class.getResource("/res/PicadiliLogo.png")).getImage().getScaledInstance(300, 330, Image.SCALE_SMOOTH);
	private Image user = new ImageIcon(loginsyst.class.getResource("/res/UsernameLogo.png")).getImage().getScaledInstance(30, 30, Image.SCALE_SMOOTH);
	private Image pass_logo = new ImageIcon(loginsyst.class.getResource("/res/passLogin.png")).getImage().getScaledInstance(30, 30, Image.SCALE_SMOOTH);

	private JFrame frame;
	private JTextField txtUsername;
	private JPasswordField txtPassword;
	private JLabel lblauthentication = new JLabel("");
	

	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					loginsyst window = new loginsyst();
					window.frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the application.
	 */
	public loginsyst() {
		initialize();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initialize() {
		
		frame = new JFrame();
		frame.setUndecorated(true);
		frame.setBackground(new Color(0.1f, 0.1f, 0.1f,0.9f));
		frame.getContentPane().setBackground(new Color(255, 255, 153));
		frame.setBounds(100, 100, 669, 381);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setLocationRelativeTo(null);
		frame.getContentPane().setLayout(null);
		Cursor cur = new Cursor (Cursor.HAND_CURSOR);
		
		JPanel panel_1 = new JPanel();
		panel_1.setBounds(328, 43, 295, 309);
		panel_1.setBackground(new Color(255, 215, 0));
		frame.getContentPane().add(panel_1);
		panel_1.setLayout(null);
		
				
				JPanel panel_2 = new JPanel();
				panel_2.setBounds(21, 160, 253, 37);
				panel_1.add(panel_2);
				panel_2.setBackground(Color.WHITE);
				panel_2.setLayout(null);
				
				txtPassword = new JPasswordField();
				txtPassword.setForeground(Color.BLACK);
				txtPassword.addFocusListener(new FocusAdapter() {
					@Override
					public void focusGained(FocusEvent e) {
						if (txtPassword.getText().equals("Password")) {
						txtPassword.setEchoChar('●');
						txtPassword.setText("");
					}
						else {
							txtPassword.selectAll();
						}
					}	
					@Override
					public void focusLost(FocusEvent e) {
						if (txtPassword.getText().equals("")) {
							txtPassword.setEchoChar((char)0);
							txtPassword.setText("Password");
						}
					}
				});
				    
				txtPassword.setEchoChar((char)0);
				txtPassword.setBorder(null);
				txtPassword.setText("Password");
				txtPassword.setBounds(10, 11, 192, 20);
				panel_2.add(txtPassword);
				
				
				JLabel lblpassLogo = new JLabel("");
				lblpassLogo.setBounds(212, 4, 38, 30);
				lblpassLogo.setHorizontalAlignment(SwingConstants.CENTER);
				lblpassLogo.setIcon(new ImageIcon (pass_logo));
				panel_2.add(lblpassLogo);
				
				JPanel panel = new JPanel();
				panel.setBounds(21, 109, 253, 38);
				panel_1.add(panel);
				panel.setBackground(Color.WHITE);
				panel.setLayout(null);
				
				txtUsername = new JTextField(10);
				txtUsername.setForeground(Color.BLACK);
				txtUsername.addFocusListener(new FocusAdapter() {
					@Override
					public void focusGained(FocusEvent e) {
						if(txtUsername.getText().equals("Username")) {
							txtUsername.setText("");
						}
						else {
							txtUsername.selectAll();
						}
					}
					@Override
					public void focusLost(FocusEvent e) {
						if(txtUsername.getText().equals("")) {
							txtUsername.setText("Username");
						}
					}
				});
				txtUsername.setBorder(null);
				txtUsername.setBounds(10, 11, 192, 20);
				panel.add(txtUsername);
				txtUsername.setText("Username");
				
				JLabel lblUserLogo = new JLabel("");
				lblUserLogo.setBounds(212, 4, 38, 30);
				panel.add(lblUserLogo);
				lblUserLogo.setHorizontalAlignment(SwingConstants.CENTER);
				lblUserLogo.setIcon(new ImageIcon (user));
				
				JLabel lblNewLabel_1 = new JLabel("ADMIN LOG IN");
				lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
				lblNewLabel_1.setFont(new Font("Tahoma", Font.BOLD, 16));
				lblNewLabel_1.setBounds(10, 32, 271, 37);
				panel_1.add(lblNewLabel_1);
				lblauthentication.setForeground(new Color(255, 0, 0));
				lblauthentication.setFont(new Font("Tahoma", Font.PLAIN, 11));
				
				lblauthentication.setBounds(31, 208, 223, 14);
				panel_1.add(lblauthentication);
				
				JButton btnlogin = new JButton("LOG IN");
				btnlogin.setBorderPainted(false);
				btnlogin.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
				btnlogin.setBorder(new BevelBorder(BevelBorder.LOWERED, null, null, null, null));
				btnlogin.addActionListener(new ActionListener() {
					public void actionPerformed(ActionEvent e) {
						try {
					        int key = 58;
					        BufferedReader reader = new BufferedReader(new FileReader("admin.txt"));
					        String line;
					        while ((line = reader.readLine()) != null) {
					        	 try {
					                 
					        	StringTokenizer stn = new StringTokenizer (line);
					        	String username =  stn.nextToken();
					        	String pass = stn.nextToken();
					        	
					        	char [] chars = username.toCharArray();
					        	
					        	String UN = "";
					        	for(char c : chars) {
					        		c-= key;
					        		UN = UN + c;
					        		
					        	}
					        	//System.out.print(UN);
					        	
					        	//System.out.print("    ");
					        	String PW = "";
					            char [] chara = pass.toCharArray();
					        	
					            	for(char c : chara) {
					        	    	c-= key;
					        	    	PW = PW + c;
					        	 }
					            //	System.out.print(PW);
					            	
					        	 if (txtUsername.getText().equals(UN) && txtPassword.getText().equals(PW)) {
					             	//new window
					        	    //Make another Java program that contains the Menu or the Main page of HRM System.        	   
					             } 
					        	 else if  (txtUsername.getText().equals("") || txtPassword.getText().equals("") || txtUsername.getText().equals(UN) || txtPassword.getText().equals(PW)) {
					             	lblauthentication.setText("Please input all requirements!");
					             }
					        	 else {
					        		lblauthentication.setText("Invalid Credentials!");
						       		 main(null);
					        	 }
					        	 } catch (Exception ignored) {}
					        }
					        reader.close();
					        }catch(IOException e1) {
					        	//System.exit(0);
					        }
					}
				});
				btnlogin.setBackground(new Color(204, 153, 0));
				btnlogin.setFont(new Font("Tahoma", Font.BOLD, 13));
				btnlogin.setBounds(23, 233, 251, 37);
				panel_1.add(btnlogin);
				txtUsername.setVisible(true);
				
				JLabel lblClose = new JLabel("X");
				lblClose.setHorizontalAlignment(SwingConstants.CENTER);
				lblClose.addMouseListener(new MouseAdapter() {
					@Override
					public void mouseClicked(MouseEvent e) {
						System.exit(0);
					}
					@Override
					public void mouseEntered(MouseEvent e) {
						lblClose.setForeground(Color.RED);
					}
					public void mouseExited(MouseEvent e) {
						lblClose.setForeground(Color.WHITE);
					}
					
				});
				lblClose.setAlignmentX(Component.CENTER_ALIGNMENT);
				lblClose.setForeground(new Color(240, 248, 255));
				lblClose.setFont(new Font("Comic Sans MS", Font.BOLD, 14));
				lblClose.setBounds(639, 11, 20, 20);
				frame.getContentPane().add(lblClose);
				
				JLabel lblPicadiliLogo = new JLabel("");
				lblPicadiliLogo.setHorizontalAlignment(SwingConstants.CENTER);
				lblPicadiliLogo.setBounds(27, 43, 278, 309);
				lblPicadiliLogo.setIcon(new ImageIcon (img_logo));
				frame.getContentPane().add(lblPicadiliLogo);
	}
}
