import java.io.File;
import java.util.Scanner;

public class LeerCodigo4JSON {

    public static void main(String[] args) {

        try {

            File archivo = new File("sumas.json");

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
