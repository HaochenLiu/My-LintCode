/*
445. Cosine Similarity

Cosine similarity is a measure of similarity between two vectors of an inner product space that measures the cosine of the angle between them. The cosine of 0° is 1, and it is less than 1 for any other angle.
See wiki: Cosine Similarity
Here is the formula:

Given two vectors A and B with the same size, calculate the cosine similarity.
Return 2.0000 if cosine similarity is invalid (for example A = [0] and B = [0]).
Have you met this question in a real interview?
Example
Given A = [1, 2, 3], B = [2, 3 ,4].
Return 0.9926.
Given A = [0], B = [0].
Return 2.0000
*/

class Solution {
public:
    /**
     * @param A: An integer array.
     * @param B: An integer array.
     * @return: Cosine similarity.
     */
    double cosineSimilarity(vector<int> A, vector<int> B) {
        // write your code here
        int na = A.size();
        int nb = B.size();
        if(na != nb) return 2.0;
        if(na == 0) return 2.0;
        if((na == 1 && A[0] == 0) && (nb == 1 && B[0] == 0)) return 2.0;
        if((na == 1 && A[0] == 0) || (nb == 1 && B[0] == 0)) return 1.0;
        double n = 0.0;
        double d = 0.0;
        double Asquare = 0.0;
        double Bsquare = 0.0;

        for(int i = 0; i < na; i++) {
            Asquare += (A[i] * A[i]);
            Bsquare += (B[i] * B[i]);
            n += (A[i] * B[i]);
        }
        
        if(Asquare == 0.0 || Bsquare == 0.0) {
            return 2.0;
        }
        
        return n / sqrt(Asquare) / sqrt(Bsquare);
    }
};
