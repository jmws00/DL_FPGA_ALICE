`timescale 1ns / 1ps

module pulse_generator_tb;
    // Inputs
    reg clk;
    reg [31:0] set_time;
    reg rst;

    // Output
    wire pulse_out;

    // Instantiate the pulse_generator module
    pulse_generator uut (
        .clk(clk),
        .set_time(set_time),
        .rst(rst),
        .pulse_out(pulse_out)
    );

    // Clock generation
    initial begin
        clk = 0;
        forever #5 clk = ~clk; // 100 MHz clock (10 ns period)
    end

    // Test stimulus
    initial begin
        // Initialize inputs
        rst = 1;
        set_time = 32'd15; // Set the time to generate the pulse after 15 clock cycles
        
        // Apply reset
        #10 rst = 0;
        
        // Observe pulse generation after the set time
        #200;
        
        // End simulation
        $stop;
    end

    // Monitor outputs
    initial begin
        $monitor("At time %t, set_time = %d, pulse_out = %b", $time, set_time, pulse_out);
    end
endmodule
