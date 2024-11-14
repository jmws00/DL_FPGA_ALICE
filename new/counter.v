// Modul Verilog generujacy pojedynczy impuls na wyjsciu
module pulse_generator(
    input wire clk,          // Zegar systemowy
    input wire [31:0] set_time,  // Czas ustawiony przez uzytkownika
    input wire rst,          // Reset
    output reg pulse_out     // Wyjscie impulsu
);

    reg [31:0] counter;      // Licznik cykli zegara

    always @(posedge clk or posedge rst) begin
        if (rst) begin
            counter <= 32'd0;
            pulse_out <= 1'b0;
        end else begin
            // Zwiekszanie licznika przy kazdym takcie zegara
            if (counter == set_time) begin
                pulse_out <= 1'b1; // Generowanie impulsu w zadanym momencie
            end else begin
                pulse_out <= 1'b0;
            end
            counter <= counter + 1;
        end
    end
endmodule
