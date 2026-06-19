import java.io.File;
import java.util.Scanner;

public class LeerCodigo2CSV {

    public static void main(String[] args) {

        try {

            File archivo = new File("suma.csv");

            Scanner lector = new Scanner(archivo);

            while (lector.hasNextLine()) {

                String linea = lector.nextLine();
                System.out.println(linea);

            }

            lector.close();

        } catch (Exception e) {
            System.out.println("Error al leer el archivo");
        }
    }
}
