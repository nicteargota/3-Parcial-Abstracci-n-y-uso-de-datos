import java.io.File;
import java.util.Scanner;

public class LeerTiposTXT {

    public static void main(String[] args) {

        try {

            Scanner lector = new Scanner(new File("tipos.txt"));

            while(lector.hasNextLine()){
                System.out.println(lector.nextLine());
            }

            lector.close();

        } catch(Exception e){
            System.out.println("Error");
        }
    }
}
