
# Finding Principal Component using Power Iteration Method

This repository contains a C++23 implementation of the Power Iteration Method for finding the first principal component of a dataset. The goal of this project is educational: to help understand the intuition behind eigenvector calculation and principal component analysis (PCA). For real-world applications, it is recommended to use established libraries (such as Eigen or Scikit-learn) that rely on efficient Singular Value Decomposition (SVD) methods.

---

## Power Iteration Method

This algorithm follows these steps:

1. **Start with a guess for the first principal component vector,** `p_1` (a naive guess could be random or all zeros).

2. **Calculate an estimate of the first score vector** `t_1`:

![t1 = X p1](https://latex.codecogs.com/png.latex?t_1%20%3D%20X%20p_1)

3. **Normalize** `p_1`. First, calculate the length (L) of `p_1`:

![L = sum p_i^2](https://latex.codecogs.com/png.latex?L%20%3D%20%5Csum_%7Bi%7D%7Bp_%7Bi%2C1%7D%5E%7B2%7D%7D)

Then normalize:

![p_j normalization](https://latex.codecogs.com/png.latex?p_j%20%3D%20%5Cfrac%7Bp_j%7D%7B%5Csqrt%7BL%7D%7D)

4. **Update your guess for** `t_1` **by calculating:**

![t1 = X p1](https://latex.codecogs.com/png.latex?t_1%20%3D%20X%20p_1)

5. **Compare the new value of** `t_1` **with the old value by calculating:**

![delta calculation](https://latex.codecogs.com/png.latex?%5CDelta%20%3D%20%5Cleft%5C%7C%20t_%7B%5Ctext%7Bold%7D%7D%20-%20t_%7B%5Ctext%7Bnew%7D%7D%20%5Cright%5C%7C%5E2)

If `delta` is below the tolerance threshold (for example, `0.001`), the process has converged. Otherwise, go back to step 2.

6. **Shrink the data matrix by calculating:**

![X_shrunk](https://latex.codecogs.com/png.latex?X_%7B%5Ctext%7Bshrunk%7D%7D%20%3D%20X%20-%20t_1%20p_1%5ET)

This step "peels off" the information about the principal component from the data matrix so that the next component can be calculated.

7. **Go back to step 1 to calculate the next principal component.**

---

## Why does this method work?
The power iteration method works because when you repeatedly multiply a vector by the data matrix (or covariance matrix), the direction of that vector converges toward the eigenvector associated with the largest eigenvalue. Over multiple iterations, smaller eigenvalue components decay, and the dominant eigenvector emerges.

This eigenvector represents the direction of maximum variance — the first principal component.

---

## Usage
- Clone the repository.
- Compile using any C++23 compliant compiler.
- Run the executable to see the step-by-step power iteration process.

## License
This project is licensed under the MIT License.

---

### Tip
For real-world or production usage, use optimized numerical libraries or built-in PCA functions in Python (scikit-learn), R, or MATLAB.
