import { Editor as MonacoEditor } from '@monaco-editor/react';

export default function Editor({ value, onChange }) {
  return (
    <MonacoEditor
      height="100%"
      language="c"
      theme="vs-dark"
      value={value}
      onChange={(val) => onChange(val ?? '')}
      options={{
        fontSize: 14,
        minimap: { enabled: false },
        scrollBeyondLastLine: false,
        automaticLayout: true,
        wordWrap: 'on',
        tabSize: 2
      }}
    />
  );
}
