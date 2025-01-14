`timescale 1ns / 1ps

module signal_generator_tb;

    // Parameters
    parameter WIDTH = 8;
    parameter T2 = 9;

    // Inputs
    reg clk;
    reg reset;
    reg [WIDTH-1:0] N;
    reg [31:0] T1;

    // Output
    wire signal_out;

    // Instantiate the Unit Under Test (UUT)
    signal_generator #(
        .WIDTH(WIDTH),
        .T2(T2)
    ) uut (
        .clk(clk),
        .reset(reset),
        .N(N),
        .T1(T1),
        .signal_out(signal_out)
    );

    // Clock generation
    initial begin
        clk = 1;
        forever #0.5 clk = ~clk; 
    end

    // Test sequence
    initial begin
        // Initialize inputs
        reset = 1;
        N = 8'b11101101; // Example pattern
        T1 = 32'd1000;     // Repeat every 50 clock cycles

        // Wait for the reset to propagate
        #20;
        reset = 0;

        // Observe the signal output for several cycles
        #1500;

        

        // Finish simulation
        $finish;
    end


endmodule
