"use client";

import { useState, useEffect } from "react";

interface Business {
  id: string;
  name: string;
  type: string;
  isoStandards: string[];
  revenue: number;
  profit: number;
  // Add more economy-related fields as needed
}

export default function BusinessAnalyzerPage() {
  const [businesses, setBusinesses] = useState<Business[]>([]);
  const [filteredBusinesses, setFilteredBusinesses] = useState<Business[]>([]);
  const [searchTerm, setSearchTerm] = useState<string>("");
  const [selectedBusinessType, setSelectedBusinessType] = useState<string>("All");
  const [selectedIsoStandard, setSelectedIsoStandard] = useState<string>("All");
  const [sortBy, setSortBy] = useState<keyof Business | "">("");
  const [sortOrder, setSortOrder] = useState<"asc" | "desc">("asc");
  const [error, setError] = useState<string>("");

  // Mock Data for initial development
  const mockBusinesses: Business[] = [
    {
      id: "1",
      name: "Tech Solutions Inc.",
      type: "Technology",
      isoStandards: ["ISO 9001", "ISO 27001"],
      revenue: 1000000,
      profit: 200000,
    },
    {
      id: "2",
      name: "Global Logistics Co.",
      type: "Logistics",
      isoStandards: ["ISO 14001"],
      revenue: 500000,
      profit: 80000,
    },
    {
      id: "3",
      name: "Green Energy Corp.",
      type: "Energy",
      isoStandards: ["ISO 9001", "ISO 14001"],
      revenue: 1200000,
      profit: 300000,
    },
    {
      id: "4",
      name: "Creative Marketing Agency",
      type: "Marketing",
      isoStandards: [],
      revenue: 300000,
      profit: 50000,
    },
    {
      id: "5",
      name: "Food Services Ltd.",
      type: "Food & Beverage",
      isoStandards: ["ISO 22000"],
      revenue: 700000,
      profit: 150000,
    },
  ];

  // Effect to load data (initially mock data)
  useEffect(() => {
    // In a real application, you would fetch data from your API here.
    // Example: fetch('/api/businesses').then(res => res.json()).then(data => { setBusinesses(data); setFilteredBusinesses(data); });
    setBusinesses(mockBusinesses);
    setFilteredBusinesses(mockBusinesses);
  }, []);

  // Effect for filtering and sorting
  useEffect(() => {
    let updatedBusinesses = businesses.filter((business) =>
      business.name.toLowerCase().includes(searchTerm.toLowerCase()) ||
      business.type.toLowerCase().includes(searchTerm.toLowerCase()) ||
      business.isoStandards.some(iso => iso.toLowerCase().includes(searchTerm.toLowerCase()))
    );

    if (selectedBusinessType !== "All") {
      updatedBusinesses = updatedBusinesses.filter(
        (business) => business.type === selectedBusinessType
      );
    }

    if (selectedIsoStandard !== "All") {
      updatedBusinesses = updatedBusinesses.filter((business) =>
        business.isoStandards.includes(selectedIsoStandard)
      );
    }

    if (sortBy) {
      updatedBusinesses.sort((a, b) => {
        const aValue = a[sortBy as keyof Business];
        const bValue = b[sortBy as keyof Business];

        if (typeof aValue === "number" && typeof bValue === "number") {
          return sortOrder === "asc" ? aValue - bValue : bValue - aValue;
        }
        if (typeof aValue === "string" && typeof bValue === "string") {
          return sortOrder === "asc" ? aValue.localeCompare(bValue) : bValue.localeCompare(aValue);
        }
        return 0;
      });
    }

    setFilteredBusinesses(updatedBusinesses);
  }, [businesses, searchTerm, selectedBusinessType, selectedIsoStandard, sortBy, sortOrder]);

  const handleSearchChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    setSearchTerm(e.target.value);
  };

  const handleBusinessTypeChange = (e: React.ChangeEvent<HTMLSelectElement>) => {
    setSelectedBusinessType(e.target.value);
  };

  const handleIsoStandardChange = (e: React.ChangeEvent<HTMLSelectElement>) => {
    setSelectedIsoStandard(e.target.value);
  };

  const handleSortChange = (field: keyof Business) => {
    if (sortBy === field) {
      setSortOrder(sortOrder === "asc" ? "desc" : "asc");
    } else {
      setSortBy(field);
      setSortOrder("asc");
    }
  };

  const availableBusinessTypes = Array.from(new Set(businesses.map(b => b.type)));
  const availableIsoStandards = Array.from(new Set(businesses.flatMap(b => b.isoStandards)));

  return (
    <>
      <main className="dashboard">
        <section className="card business-analyzer-card">
          <h2>📊 Business Analyzer</h2>

          {error && (
            <div className="error-banner">
              ⚠️ {error}
            </div>
          )}

          <div className="controls">
            <input
              type="text"
              placeholder="Search by name, type, or ISO standard..."
              value={searchTerm}
              onChange={handleSearchChange}
              className="search-input"
            />

            <select
              value={selectedBusinessType}
              onChange={handleBusinessTypeChange}
              className="filter-select"
            >
              <option value="All">All Business Types</option>
              {availableBusinessTypes.map((type) => (
                <option key={type} value={type}>
                  {type}
                </option>
              ))}
            </select>

            <select
              value={selectedIsoStandard}
              onChange={handleIsoStandardChange}
              className="filter-select"
            >
              <option value="All">All ISO Standards</option>
              {availableIsoStandards.map((standard) => (
                <option key={standard} value={standard}>
                  {standard}
                </option>
              ))}
            </select>
          </div>

          <div className="business-list">
            <table>
              <thead>
                <tr>
                  <th onClick={() => handleSortChange("name")}>Name {sortBy === "name" && (sortOrder === "asc" ? "↑" :
                    "↓")}</th>
                  <th onClick={() => handleSortChange("type")}>Type {sortBy === "type" && (sortOrder === "asc" ? "↑" :
                    "↓")}</th>
                  <th>ISO Standards</th>
                  <th onClick={() => handleSortChange("revenue")}>Revenue {sortBy === "revenue" && (sortOrder === "asc" ? "↑" :
                    "↓")}</th>
                  <th onClick={() => handleSortChange("profit")}>Profit {sortBy === "profit" && (sortOrder === "asc" ? "↑" :
                    "↓")}</th>
                </tr>
              </thead>
              <tbody>
                {filteredBusinesses.map((business) => (
                  <tr key={business.id}>
                    <td>{business.name}</td>
                    <td>{business.type}</td>
                    <td>{business.isoStandards.join(", ") || "N/A"}</td>
                    <td>${business.revenue.toLocaleString()}</td>
                    <td>${business.profit.toLocaleString()}</td>
                  </tr>
                ))}
              </tbody>
            </table>
            {filteredBusinesses.length === 0 && (
              <p className="no-results">No businesses found matching your criteria.</p>
            )}
          </div>
        </section >
      </main >

      <style jsx>{`
           .business-analyzer-card {
             max-width: 1200px;
             margin: 0 auto;
           }
           .controls {
             display: flex;
             flex-wrap: wrap;
             gap: 15px;
             margin-bottom: 20px;
             justify-content: center;
             align-items: center;
           }
           .search-input, .filter-select {
             padding: 10px 15px;
             border-radius: 8px;
             border: 2px solid #374151;
             background: #1f2937;
             color: #f3f4f6;
             font-size: 14px;
             min-width: 200px;
           }
           .search-input::placeholder {
             color: #9ca3af;
           }
           .search-input:focus, .filter-select:focus {
             border-color: #4ade80;
             outline: none;
           }
           .filter-select {
             cursor: pointer;
           }
           .business-list {
             margin-top: 20px;
             overflow-x: auto;
           }
           table {
             width: 100%;
             border-collapse: collapse;
             margin-bottom: 20px;
           }
           th, td {
             border: 1px solid #374151;
             padding: 12px 15px;
             text-align: left;
             color: #f3f4f6;
           }
           th {
             background-color: #1f2937;
             cursor: pointer;
             position: relative;
           }
           th:hover {
             background-color: #2d3a4b;
           }
           tbody tr:nth-child(odd) {
             background-color: rgba(0, 0, 0, 0.1);
           }
           tbody tr:hover {
             background-color: rgba(74, 222, 128, 0.1);
           }
           .no-results {
             text-align: center;
             color: #9ca3af;
             padding: 20px;
           }
           .error-banner {
             background: rgba(220, 38, 38, 0.2);
             border: 1px solid #dc2626;
             color: #fca5a5;
             padding: 12px 16px;
             border-radius: 8px;
             margin-bottom: 20px;
             text-align: center;
           }
           .dashboard {
               padding: 20px;
               background-color: #1a202c; /* Darker background */
               min-height: 100vh;
               color: #f3f4f6; /* Light text */
           }
           .card {
               background: #2d3748; /* Slightly lighter card background */
               border-radius: 12px;
               padding: 30px;
               box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
               margin-bottom: 20px;
           }
           h2 {
               color: #4ade80; /* Green accent for titles */
               font-size: 2em;
               margin-bottom: 25px;
               text-align: center;
           }
         `}</style>
    </>
  );
}