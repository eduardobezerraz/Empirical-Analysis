set xlabel 'Tamanho da amostra'
set ylabel 'Tempo em milissegundos'
set autoscale
set grid
set terminal png
set key left top Left title 'Search from' box 3
set term post portrait color "Times-Roman" 12


set title 'Linear Search'
set output 'Plots/Linearsearch_plot.pdf'
plot 'Data/linear.txt' with lines lw 3

set title 'Binary Search'
set output 'Plots/BinarySearch_plot.pdf'
plot 'Data/binary.txt' with lines lw 3

set title 'Recursive Binary Search'
set output 'Plots/RecursiveBinarySearch_plot.pdf'
plot 'Data/binary_r.txt'  with lines lw 3

set title 'Ternary Search'
set output 'Plots/TernarySearch_plot.pdf'
plot 'Data/ternary.txt' with lines lw 3
  
set title 'Recursive Ternary Search'
set output 'Plots/RecusiveTernarySearch_plot.pdf'
plot 'Data/ternary_r.txt' with lines lw 3   

set title 'Jump Search'
set output 'Plots/JumpSearch_plot.pdf'
plot 'Data/jump.txt' with lines lw 3

set title 'Fibonacci Search'
set output 'Plots/FibonacciSearch_plot.pdf'
plot 'Data/fibonacci.txt' with lines lw 3

set title 'Iterative VS Recursive'
set output 'Plots/IterVsRecur.pdf'
plot 'Data/binary.txt' w l lw 3 smooth csplines, 'Data/binary_r.txt' w l lw 3 smooth csplines

set xrange[0:50000]
set title 'Linear VS Jump'
set output 'Plots/LinearVsJump.pdf'
plot 'Data/linear.txt' w l lw 3 smooth csplines, 'Data/jump.txt' w l lw 3 smooth csplines

set autoscale

set yrange[0:0.01]
set title 'BinTerFib'
set output 'Plots/Bin_Ter_Fib.pdf'
plot 'Data/fibonacci.txt' w l lw 3 smooth csplines, 'Data/binary.txt' w l lw 3 smooth csplines, 'Data/ternary.txt' w l lw 3 smooth csplines

set autoscale

set xrange[0:100]
set title 'Linear VS Bin'
set output 'Plots/LinXBin.pdf'
plot 'Data/linear.txt' w l lw 3 smooth csplines, 'Data/binary.txt' w l lw 3 smooth csplines


