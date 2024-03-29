# sklearn库LinearRegression函数理解

首先，sklearn的LinearRegression函数获取参数主要靠：sqarse_lsqr()或linalg.lstsq()，若训练集X是稀疏矩阵，则使用前者

## fit()

  ```python
  if sp.issparse(X):#如果X是稀疏矩阵
      if y.ndim < 2:
          out = sparse_lsqr(X, y)
          self.coef_ = out[0]
          self._residues = out[3]
      else:
          # sparse_lstsq cannot handle y with shape (M, K)
          outs = Parallel(n_jobs=n_jobs_)(
              delayed(sparse_lsqr)(X, y[:, j].ravel())
              for j in range(y.shape[1]))
          self.coef_ = np.vstack(out[0] for out in outs)
          self._residues = np.vstack(out[3] for out in outs)
  else:
      self.coef_, self._residues, self.rank_, self.singular_ = \
          linalg.lstsq(X, y)
      self.coef_ = self.coef_.T
  ```

以上是fit()函数源码，即判断X的形式决定计算线性回归参数的方式

* 如果y的维度小于2，并没有并行操作
* 如果训练集X是稀疏矩阵，就用sparse_lsqr()求解
  先检查训练集再决定运算方式，增加效率



## linalg.lstsq()

sklearn.linear model.LinearRegresslon是用普通的最小二乘法（OLS）求解线性回归方程参数的

但此处使用的是scipy.linalg.lstsq()

### scipy.linalg.lstsq()

scipy提供了三种方法来求解least-squres problem最小均方问题，即模型优化目标。其提供了三个选项gelsd,gelsy,geless，这些参数数传入了get_1apack funcs()。这三个参数实际上是C函数名，函数是从LAPACK(Linear Algebra PACKage)中获得的。

gelsd:它是用singular value decomposition ofA and a divide and conquer method方法来求解线性回归方程参数的。

gelsy:computes the minimum-norm solution to a real/complex linear least squares problem

gelss: Computes the minimum-norm solution to a linear least squares problem using the singular value decomposition of A.

```python
if driver in ('gelss', 'gelsd'):
    if driver == 'gelss':
        lwork = _compute_lwork(lapack_lwork, m, n, nrhs, cond)
        v, x, s, rank, work, info = lapack_func(a1, b1, cond, lwork,
                                                overwrite_a=overwrite_a,
                                                overwrite_b=overwrite_b)

    elif driver == 'gelsd':
        if real_data:
            lwork, iwork = _compute_lwork(lapack_lwork, m, n, nrhs, cond)
            x, s, rank, info = lapack_func(a1, b1, lwork,
                                           iwork, cond, False, False)
        else:  # complex data
            lwork, rwork, iwork = _compute_lwork(lapack_lwork, m, n,
                                                 nrhs, cond)
            x, s, rank, info = lapack_func(a1, b1, lwork, rwork, iwork,
                                           cond, False, False)
```



scipy.linalg.lstsq()方法使用gelsd求解(并没有为用户提供选项)。


## sqarse_lsqr()

sqarse_1sqr()方法用来计算X是稀疏矩阵时的模型系数。sparse1sqr()就是不同版本的scipy.sparse.linalg.1sgrO

参考自论文C.C.Paige and M. A. Saunders (1982a). 

> "LSOR: An algorithm for sparse linear euations and sparse least souares"

```python
if sp_version < (0, 15):
    # Backport fix for scikit-learn/scikit-learn#2986 / scipy/scipy#4142
    from ._scipy_sparse_lsqr_backport import lsqr as sparse_lsqr
else:
    from scipy.sparse.linalg import lsqr as sparse_lsqr
```