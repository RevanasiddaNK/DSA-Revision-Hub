class Solution {
public:
    #define base 256 // Base for hash calculation (number of characters in the ASCII table)
    #define mod 257  // Prime number to reduce collisions and limit hash values

    // Using Rabin-Karp Algorithm for pattern matching
    int strStr(string text, string pattern) {
        int m = pattern.size(); // Length of the pattern
        int n = text.size();    // Length of the text
        
        if (m > n) return -1;   // If the pattern is longer than the text, no match is possible

        int h = 1; // `h` will hold the value of `base^(m-1) % mod`
        
        // Compute the value of `h` as `base^(m-1) % mod`
        for (int i = 1; i < m; i++) {
            h = (h * base) % mod;
        }

        int p = 0, t = 0; // Hash values for the pattern (`p`) and the first window of text (`t`)

        // Calculate initial hash values for pattern and first window of text
        for (int i = 0; i < m; i++) {
            p = ((p * base) + pattern[i]) % mod; // Hash for pattern
            t = ((t * base) + text[i]) % mod;    // Hash for first `m` characters of text
        }

        // Slide the window over the text
        for (int i = 0; i <= n - m; i++) {
            // Check if hash values match
            if (p == t) {
                // If hash matches, perform character-by-character comparison
                int j = 0;
                for (; j < m && i + j < n; j++) {
                    if (text[i + j] != pattern[j]) {
                        break;
                    }
                }
                if (j == m) { // If the entire pattern matches
                    return i; // Return the starting index of the match
                }
            }

            // Calculate hash for the next window
            if (i < n - m) {
                t = (base * (t - text[i] * h) + text[i + m]) % mod; // Sliding hash formula
                if (t < 0) t += mod; // Ensure hash is non-negative
            }
        }

        return -1; // If no match is found
    }
};

/*
    Time Complexity: O(m+n) worst case O(mn)
    Space Complexity: O(1)
*/
