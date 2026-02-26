"use server";

import fs from "fs/promises";
import path from "path";

export async function fetchLatestSensorData() {
  try {
    const filePath = path.join(process.cwd(), "data", "bme280data.csv");
    const content = await fs.readFile(filePath, "utf-8");
    const lines = content.trim().split("\n");
    if (lines.length < 2) return null;

    const lastLine = lines[lines.length - 1];
    const parts = lastLine.split(",");

    return {
      date: parts[0]?.trim(),
      temp: parts[1]?.trim(),
      pressure: parts[2]?.trim(),
      humidity: parts[3]?.trim(),
    };
  } catch (error) {
    console.error("Error reading CSV:", error);
    return null;
  }
}
