import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class AuthSystemTest {
    @Test
    public void testDynamicStrings() {
        String base = "SECRET_123";
        String dynamicInput = new String("SECRET_123"); // Forces a new object address
        
        assertTrue(AuthSystem.verifyToken(base, dynamicInput), "Token verification failed for structural copies!");
    }
}
