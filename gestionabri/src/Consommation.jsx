import React, { useEffect, useState } from 'react';

function Consommation() {
  const [data, setData] = useState({ edf: 0, solaire: 0 });

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await fetch('http://localhost:3001/api/consommation');
        const result = await response.json();
        setData(result);
      } catch (error) {
        console.error('Erreur de récupération des données:', error);
      }
    };

    fetchData();
    const interval = setInterval(fetchData, 1000);
    return () => clearInterval(interval);
  }, []);

  return (
    <div>
      <h2>Consommation</h2>
      <div>
        <label>EDF (W): </label>
        <input type="text" readOnly value={data.edf} />
      </div>
      <div>
        <label>Solaire (W): </label>
        <input type="text" readOnly value={data.solaire} />
      </div>
    </div>
  );
}

export default Consommation;
