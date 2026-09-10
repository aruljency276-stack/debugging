public class TestGrade {
    public static void main(String[] args) {
        // Create strings dynamically to bypass the internal JVM string constant pool optimization
        String[] studentGrades = { new String("PASS"), new String("FAIL"), new String("PASS") };
        String passingKey = new String("PASS");

        int passingCount = GradeEvaluator.countPassingGrades(studentGrades, passingKey);
        System.out.println("[LOG] Counted Passing Grades: " + passingCount);

        if (passingCount != 2) {
            System.err.println("❌ TEST FAILED: String value mismatch! Expected 2, Got: " + passingCount);
            System.exit(1);
        }
        System.out.println("✅ TEST PASSED: Content comparison correct.");
    }
}
