# ilqgames
Iterative Linear-Quadratic Games - a new, real-time solver for _N_-player general differential games.

## Paper
For a full description of the algorithm itself and examples of how it can be applied in collision-avoidance problems, please refer to the [paper](https://arxiv.org/abs/1909.04694).

If you find this repository useful, please do cite the paper:
```
@misc{fridovichkeil2019efficient,
    title={Efficient Iterative Linear-Quadratic Approximations for Nonlinear Multi-Player General-Sum Differential Games},
    author={David Fridovich-Keil and Ellis Ratner and Anca D. Dragan and Claire J. Tomlin},
    year={2019},
    eprint={1909.04694},
    archivePrefix={arXiv},
    primaryClass={eess.SY}
}
```

Currently, the paper is under review at IEEE Robotics and Automation Letters. An updated link and reference will be posted upon publication.

## Primary contributor
The primary contributor is [David Fridovich-Keil](https://people.eecs.berkeley.edu/~dfk/), a fifth-year PhD student advised by Claire Tomlin in the EECS department at UC Berkeley. The best way to contact David is by email, _dfk at eecs dot berkeley dot edu_, or if you have specific questions about this repository, please post an [issue](https://github.com/HJReachability/ilqgames/issues).

## Language
An early version of the iterative linear-quadratic game algorithm was implemented in Python; it is now deprecated and stored in the `python/` directory. Ongoing and future development will proceed primarily in C++, although a colleague is building a version in Julia, which may eventually be merged here.

## Dependencies
`ilqgames` has been tested both in OS X and Ubuntu. Depending on your version of Ubuntu, you may notice a linker error related to `aclocal-XX`, which may be fixed by symlinking Ubuntu's native `aclocal` to the desired executable `aclocal-XX`. Otherwise, external dependencies are standard:

* `glog` (Google's logging tools)
* `gflags` (Google's command line flag tools)
* `opengl`, `glut` (graphics tools)
* `eigen3` (linear algebra library)

## Getting started
This repository uses the `cmake` build system and may be compiled following standard cmake protocols:
```
mkdir build && cd build
cmake ..
make -j8
```

Executables will be stored in the `bin/` directory, with the exception of `build/run_tests`, which runs unit tests. To run unit tests from the build directory, simply execute:
```
./run_tests
```

To run a particular example from the `bin/` directory, e.g., the three-player intersection:
```
./three_player_intersection
```

With any executable, a full explanation of command line arguments can be found by running:
```
./<name-of-executable> --help
```

## Extending *ilqgames*
### New examples
All specific examples, e.g. the three-player intersection, inherit from the base class `Problem`. This base class provides a number of utilities, such as warm starting, and also wraps the solver. To inherit, simply write a constructor which instantiates the appropriate solver with costs, and also set the initial state, operating point, and strategies. To see an example, consult the [ThreePlayerIntersectionExample](https://github.com/HJReachability/ilqgames/blob/master/src/three_player_intersection_example.cpp) class.

## ROS
There is a companion ROS extension under development, which may be found [here](https://github.com/HJReachability/ilqgames_ros). It is currently still marked private, but rest assured that the usage of the *ilqgames* toolbox in ROS is straightforward! If you want to implement this yourself for a custom application it is not too hard.
