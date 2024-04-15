package 문자열;

public class PS스킬체크테스트1 {
    class Solution {
        public boolean solution(String s) {
            boolean answer = false;

            int len_s = s.length();
            if (len_s != 4 && len_s != 6) return false;

            for (int i = 0; i < len_s; i++) {
                char c = s.charAt(i);
                if (c >= '0' && c <= '9') {
                    answer = true;
                } else {
                    answer = false;
                    break;
                }
            }

            return answer;
        }
    }
}
