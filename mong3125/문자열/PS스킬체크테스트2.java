package 문자열;

import java.util.*;

public class PS스킬체크테스트2 {
    class Solution {
        public int[] solution(String s) {
            int[] answer = new int[s.length()];

            HashMap<Character, Integer> alphabet = new HashMap<>();

            for (int i = 0; i < s.length(); i++) {
                char now = s.charAt(i);
                if (alphabet.containsKey(now)) {
                    answer[i] = i - alphabet.get(now);
                } else {
                    answer[i] = -1;
                }

                alphabet.put(now, i);
            }

            return answer;
        }
    }
}
