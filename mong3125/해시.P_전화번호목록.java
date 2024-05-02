import java.util.HashSet;

class Solution {
    public boolean solution(String[] phone_book) {

        HashSet<String> set = new HashSet<>();

        for (String phoneNum : phone_book) {
            set.add(phoneNum);
        }

        for (String phoneNum : phone_book) {
            for (int i = 0; i < phoneNum.length(); i++) {
                if (set.contains(phoneNum.substring(0, i))) return false;
            }
        }

        return true;
    }
}