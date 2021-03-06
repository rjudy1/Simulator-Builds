/*
Project:  Assembler
Class:    Computer Architecture
Author:   Rachael Judy
Date:     2.18.2020
Purpose:  Assemble .asm files into a symbol and bin table
 */
package JavaAssembler;

import java.io.*;
import java.util.*; // HashMap, vector
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;
import static java.lang.Integer.parseInt;

public class JavaAssembler extends javax.swing.JFrame {
    public JavaAssembler() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">                          
    private void initComponents() {

        jScrollPane1 = new javax.swing.JScrollPane();
        assemblyFileTextArea = new javax.swing.JTextArea();
        jScrollPane2 = new javax.swing.JScrollPane();
        symbolFileTextArea = new javax.swing.JTextArea();
        jScrollPane3 = new javax.swing.JScrollPane();
        binFileTextArea = new javax.swing.JTextArea();
        assembleButton = new javax.swing.JButton();
        exitButton = new javax.swing.JButton();
        inputFilename = new javax.swing.JTextField();
        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        messageArea = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel6 = new javax.swing.JLabel();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        assemblyFileTextArea.setEditable(false);
        assemblyFileTextArea.setColumns(20);
        assemblyFileTextArea.setFont(new java.awt.Font("Courier New", 0, 13)); // NOI18N
        assemblyFileTextArea.setRows(5);
        jScrollPane1.setViewportView(assemblyFileTextArea);

        symbolFileTextArea.setEditable(false);
        symbolFileTextArea.setColumns(20);
        symbolFileTextArea.setFont(new java.awt.Font("Courier New", 0, 13)); // NOI18N
        symbolFileTextArea.setRows(5);
        jScrollPane2.setViewportView(symbolFileTextArea);

        binFileTextArea.setEditable(false);
        binFileTextArea.setColumns(20);
        binFileTextArea.setFont(new java.awt.Font("Courier New", 0, 13)); // NOI18N
        binFileTextArea.setRows(5);
        jScrollPane3.setViewportView(binFileTextArea);

        inputFilename.setFocusTraversalPolicy(null);
        inputFilename.setFocusTraversalPolicyProvider(true);
        inputFilename.setNextFocusableComponent(assembleButton);

        assembleButton.setText("Assemble");
        assembleButton.setFocusTraversalPolicyProvider(true);
        assembleButton.setNextFocusableComponent(exitButton);
        assembleButton.setRequestFocusEnabled(false);
        assembleButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                assembleButtonMouseClicked(evt);
            }
        });

        exitButton.setText("Exit");
        exitButton.setFocusCycleRoot(true);
        exitButton.setFocusTraversalPolicyProvider(true);
        exitButton.setNextFocusableComponent(inputFilename);
        exitButton.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseClicked(java.awt.event.MouseEvent evt) {
                exitButtonMouseClicked(evt);
            }
        });


        jLabel1.setText("Enter the filename of the .asm file:");

        jLabel2.setText("Computer Architecture Assembler");

        jLabel3.setText("Rachael Judy");

        messageArea.setText("Corresponding .asm and .bin files will be generated in same location.");

        jLabel4.setText("Input assembly file:");
        jLabel4.setToolTipText("");

        jLabel5.setText("Symbol file:");

        jLabel6.setText("Bin file:");

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(inputFilename, javax.swing.GroupLayout.PREFERRED_SIZE, 189, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.PREFERRED_SIZE, 230, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jLabel4, javax.swing.GroupLayout.PREFERRED_SIZE, 152, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(layout.createSequentialGroup()
                                .addGap(6, 6, 6)
                                .addComponent(messageArea, javax.swing.GroupLayout.PREFERRED_SIZE, 328, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(exitButton, javax.swing.GroupLayout.PREFERRED_SIZE, 77, javax.swing.GroupLayout.PREFERRED_SIZE)
                                    .addComponent(assembleButton))
                                .addGap(18, 18, 18))
                            .addGroup(layout.createSequentialGroup()
                                .addGap(41, 41, 41)
                                .addComponent(jLabel5, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 265, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 254, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel6, javax.swing.GroupLayout.PREFERRED_SIZE, 97, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 256, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addContainerGap())))
            .addGroup(layout.createSequentialGroup()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addGap(315, 315, 315)
                        .addComponent(jLabel2))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(360, 360, 360)
                        .addComponent(jLabel3)))
                .addGap(0, 0, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                .addGap(22, 22, 22)
                .addComponent(jLabel2, javax.swing.GroupLayout.PREFERRED_SIZE, 13, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel3)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 0, Short.MAX_VALUE)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel1)
                            .addComponent(messageArea, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(inputFilename, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.UNRELATED)
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                            .addComponent(jLabel4)
                            .addComponent(jLabel5)
                            .addComponent(jLabel6))
                        .addGap(3, 3, 3))
                    .addGroup(layout.createSequentialGroup()
                        .addGap(5, 5, 5)
                        .addComponent(assembleButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(exitButton)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 22, Short.MAX_VALUE)))
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.DEFAULT_SIZE, 376, Short.MAX_VALUE)
                    .addComponent(jScrollPane2)
                    .addComponent(jScrollPane1))
                .addContainerGap())
        );

        messageArea.getAccessibleContext().setAccessibleName("");

        pack();
    }// </editor-fold>                        

    private void assembleButtonMouseClicked(java.awt.event.MouseEvent evt) {                                            
        assemblyFileTextArea.setText("");
        binFileTextArea.setText("");
        symbolFileTextArea.setText("");
        try {
            assembleFile();
        } catch (IOException ex) {
            Logger.getLogger(JavaAssembler.class.getName()).log(Level.SEVERE, null, ex);
        }
    }                                           

    private void exitButtonMouseClicked(java.awt.event.MouseEvent evt) {                                        
        System.exit(0);
    }                                       

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(JavaAssembler.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(JavaAssembler.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(JavaAssembler.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(JavaAssembler.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new JavaAssembler().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify                     
    private javax.swing.JButton assembleButton;
    private javax.swing.JTextArea assemblyFileTextArea;
    private javax.swing.JTextArea binFileTextArea;
    private javax.swing.JButton exitButton;
    private javax.swing.JTextField inputFilename;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JLabel messageArea;
    private javax.swing.JTextArea symbolFileTextArea;
    // End of variables declaration                   

    private void assembleFile() throws IOException {
      BufferedReader inputFile = null;
      BufferedWriter symFile = null;
      BufferedWriter binFile = null;
      
      String filename = inputFilename.getText();
      ArrayList<String> inputLines = new ArrayList<>();
      
      try {
         inputFile = new BufferedReader(new FileReader(filename));
         filename = filename.substring(0, filename.length()-4);
         
         // pass 1
         // create symbol file and map for symbols
         symFile = new BufferedWriter(new PrintWriter(new FileWriter(filename + ".sym")));
         Map<String, Integer> symbols = new HashMap<>();

         int counter = 0; // line counter         
         String inputLine;
         // loop through each line of the file
         while ((inputLine = inputFile.readLine()) != null) {
            for (int i = inputLine.length(); i < 75; i++) { // pad with spaces
               inputLine += " ";
            }
            inputLines.add(inputLine); // add to array list
            
            // writes assembly file to text area
            assemblyFileTextArea.setText(assemblyFileTextArea.getText() + inputLine + "\n"); 
            
            // checks origin
            if (inputLine.substring(5, 8).equals("ORG")) {
                counter = parseInt(inputLine.substring(9, 12), 16);
            } else { // writes to text area and file
                if (inputLine.charAt(3) == ',') {
                    symbols.put(inputLine.substring(0, 3), counter);
                    String output = inputLine.substring(0,3) + ":  " 
                            + String.format("%1$3s", Integer.toHexString(counter)).replace(' ', '0')
                            + "  " + inputLine.substring(16).trim() + "\n";
                    symFile.write(output);
                    symbolFileTextArea.setText(symbolFileTextArea.getText() + output);
                }
                counter++;
            }
            symFile.flush();
         }
         inputFile.close();
         
         // pass 2---------------------------------------------------------------
         // reopen file, reset counter, get file writer
         counter = 0;
         binFile = new BufferedWriter(new FileWriter(filename + ".bin"));
         
         // map for commands
         Map<String, String> commandHexCode = new HashMap<>();
         commandHexCode.put("AND", "0000");
         commandHexCode.put("ADD", "1000");
         commandHexCode.put("LDA", "2000");
         commandHexCode.put("STA", "3000");
         commandHexCode.put("BUN", "4000");
         commandHexCode.put("BSA", "5000");
         commandHexCode.put("ISZ", "6000");
         commandHexCode.put("CLA", "7800");
         commandHexCode.put("CLE", "7400");
         commandHexCode.put("CMA", "7200");
         commandHexCode.put("CME", "7100");
         commandHexCode.put("CIR", "7080");
         commandHexCode.put("CIL", "7040");
         commandHexCode.put("INC", "7020");
         commandHexCode.put("SPA", "7010");
         commandHexCode.put("SNA", "7008");
         commandHexCode.put("SZA", "7004");
         commandHexCode.put("SZE", "7002");
         commandHexCode.put("HLT", "7001");
         commandHexCode.put("INP", "F800");
         commandHexCode.put("OUT", "F400");
         commandHexCode.put("SKI", "F200");
         commandHexCode.put("SKO", "F100");
         commandHexCode.put("ION", "F080");
         commandHexCode.put("IOF", "F040");         
         
         // loops through ArrayList
         for (int i = 0; i < inputLines.size(); i++) {
             inputLine = inputLines.get(i);
             
             // extract command, value, and comment
             String command = inputLine.substring(5, 8);
             String value = inputLine.substring(9, 12);
             String comment = inputLine.substring(16).trim();
             
             // check for required spaces, skips incorrectly spaced lines
             if (inputLine.charAt(4) != ' ' || inputLine.charAt(8) != ' ' || inputLine.charAt(12) != ' ') {
                         JOptionPane.showMessageDialog(null, 
                                 "Command to be written at address " + Integer.toHexString(counter) 
                                 + " is invalid and will be skipped.");
                         counter++;
                         continue;
             }
             
             String output="";
             // writes to binFile
             if (command.toUpperCase().equals("ORG")) {
                 if (counter == 0 && !value.equals("000")) {// writes a branching instruction to start of program
                     output = String.format("%1$3s", Integer.toHexString(counter)).replace(' ', '0')
                             + ":  4" + value + "  " + inputLine.substring(16).trim() + "\n";
                     binFileTextArea.setText(binFileTextArea.getText() + output);
                     binFile.write(output);
                 }
                 counter = parseInt(value, 16);
                 counter--;
             } else if (command.toUpperCase().equals("DEC")) { // decimal value at location
                 int address = parseInt(value.trim());
                 if (symbols.containsKey(inputLine.substring(0, 3))) {
                     output = String.format("%1$3s", Integer.toHexString(symbols.get(inputLine.substring(0, 3)))).replace(' ', '0') 
                         + ":  " + String.format("%1$4s", Integer.toHexString(address & parseInt("FFFF", 16))).replace(' ', '0')
                         + "  " + comment + "\n";
                 } else {
                     output = String.format("%1$3s", Integer.toHexString(counter)).replace(' ', '0')
                         + ":  " + String.format("%1$4s", Integer.toHexString(address & parseInt("FFFF", 16))).replace(' ', '0') 
                         + "  " + comment + "\n";
                 }
                 binFileTextArea.setText(binFileTextArea.getText() + output);
                 binFile.write(output);
             } else if (command.toUpperCase().equals("HEX")) { // hex value at locationint address = parseInt(value, 16);
                if (symbols.containsKey(inputLine.substring(0, 3))) { // check for label
                    output = String.format("%1$3s", Integer.toHexString(symbols.get(inputLine.substring(0, 3)))).replace(' ', '0') + ":  ";
                } else { 
                    output = String.format("%1$3s", Integer.toHexString(counter)).replace(' ', '0') + ":  ";
                }
                binFileTextArea.setText(binFileTextArea.getText() + output
                        + String.format("%1$4s", value.trim()).replace(' ', '0') + "  " + comment +"\n");
                binFile.write(output + String.format("%1$4s", value).replace(' ', '0') + "  " + comment + "\n");
             } else if (commandHexCode.containsKey(command)) { // checks on command list
                if (parseInt(commandHexCode.get(command), 16) <= 24576) { // checks for memory addressing
                     int indirect = 0;
                     if (inputLine.charAt(13) == 'I') {
                         indirect = parseInt("8000", 16);
                     }

                     int addr;
                     if (symbols.containsKey(value)) {
                         addr = symbols.get(value);
                     } else {
                         addr = parseInt(value, 16);
                     }
                     
                     // gets command in decimal form
                     int decCommand = parseInt(commandHexCode.get(command), 16) |
                             indirect | addr;
                     
                     output = String.format("%1$3s", Integer.toHexString(counter)).replace(' ', '0') + ":  "
                             + String.format("%1$4s", Integer.toHexString(decCommand)).replace(' ', '0') + "  "
                             + comment + "\n";
                 } else { // non memory addressing command
                     output = String.format("%1$3s", Integer.toHexString(counter)).replace(' ', '0') + ":  "
                             + String.format("%1$3s", commandHexCode.get(command) + "\n").replace(' ', '0');
                 }
                binFile.write(output);
                binFileTextArea.setText(binFileTextArea.getText() + output); 
             } else if (command.toUpperCase().equals("END")) { // display message when complete
                  JOptionPane.showMessageDialog(null, "Conversion Completed");
                  break;
             }
             else { // invalid command on line
                 JOptionPane.showMessageDialog(null, "Command non-existent on line "
                         + Integer.toHexString(counter));
             }
             binFile.flush();
             counter++;
         }
      } catch (FileNotFoundException e) {
        JOptionPane.showMessageDialog(null,
            "File Not Found: " + inputFilename.getText());
      } catch (IOException e) {
        JOptionPane.showMessageDialog(null,
            "Error reading file");      
      } catch (Exception e) {
        JOptionPane.showMessageDialog(null,
            e.getMessage());
      }
      finally { // close files
         if (inputFile != null) {
            inputFile.close();
         }
         if (symFile != null) {
            symFile.close();
         }
         if (binFile != null) {
            binFile.close();
         }
      }
    }
}
