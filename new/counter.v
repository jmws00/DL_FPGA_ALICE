// Module generating a single pulse at the output
module pulse_generator(
    input wire clk,          // System clock
    input wire [31:0] set_time,  // Time set by the user
    input wire rst,          // Reset
    output reg pulse_out     // Pulse output
);

    reg [31:0] counter;      // Clock cycle counter

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            counter <= 32'd0;
            pulse_out <= 1'b0;
        end else begin
            // Increment the counter at each clock tick
            if (counter == set_time) begin
                pulse_out <= 1'b1; // Generate pulse at the specified time
            end else begin
                pulse_out <= 1'b0;
            end
            counter <= counter + 1;
        end
    end
endmodule
