public class GradeEvaluator {
    public static int countPassingGrades(String[] grades, String targetPassMarker) {
        int counts = 0;
        for (String grade : grades) {
            // BUG: Student uses '==' which checks identity references, not content.
            // This fails when Java handles strings instantiated dynamically out of the string pool.
            if (grade == targetPassMarker) {
                counts++;
            }
        }
        return counts;
    }
}
