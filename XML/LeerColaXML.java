import java.io.File;
import java.util.Scanner;

public class LeerColaXML {

    public static void main(String[] args) {

        try {

            File archivo = new File("cola.xml");

            Scanner lector = new Scanner(archivo);

            while (lector.hasNextLine()) {

                System.out.println(lector.nextLine());

            }

            lector.close();

        } catch (Exception e) {

            System.out.println("Error al leer el archivo");

        }
    }
}
