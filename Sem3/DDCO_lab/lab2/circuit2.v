module circuit2(
    input A2, B2, C2,
    output Y
);

assign Y = (A2 | (C2 & B2)) | (B2 & A2);

endmodule
