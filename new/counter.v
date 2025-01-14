module signal_generator #(
    parameter WIDTH = 8, // Szerokość rejestru N
    parameter T2 = 2
)(
    input wire clk,         // Zegar
    input wire reset,       // Reset asynchroniczny
    input wire [WIDTH-1:0] N, // Rejestr sygnału
    input wire [31:0] T1,   // Czas powtarzania serii w cyklach zegara
    output reg signal_out   // Wyjście sygnału
);

    reg [31:0] clk_counter = 0;       // Licznik zegara
    reg [31:0] pulse_counter = 0;    // Licznik impulsu
    reg [WIDTH-1:0] index = 0; // Indeks bieżącego bitu w N
    

    always @(posedge clk) begin

        if (reset) begin
            // Reset wszystkich sygnałów
            clk_counter <= 0;
            pulse_counter <= 0;
            index <= 0;
            signal_out <= 0;
            
        end else begin
        // Inkrementacja licznika zegara
        clk_counter <= clk_counter + 1;
            if (clk_counter < T1) begin
                
                    if (index < WIDTH) begin
                        // Generowanie impulsu dla bieżącego bitu
                        if (pulse_counter < T2) begin
                            signal_out <= N[index];
                            pulse_counter <= pulse_counter + 1;
                        end else begin
                            // Przejście do kolejnego bitu
                            pulse_counter <= 0;
                            index <= index + 1;
                        end
                    end else begin
                        // Wszystkie bity przetworzone, wyjście na 0
                        signal_out <= 0;
                    end
                
            end else begin
                // Koniec T1, zresetuj wszystko
                clk_counter <= 0;
                pulse_counter <= 0;
                index <= 0;
                signal_out <= 0;
            end

        end
        
    end
endmodule
